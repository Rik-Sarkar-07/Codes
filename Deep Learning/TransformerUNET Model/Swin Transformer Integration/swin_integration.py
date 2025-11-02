import torch
import torch.nn as nn
import torch.nn.functional as F
import timm

# Note: The ConvBlock is assumed to be defined in model.py or backbones.py
# For this file to be standalone, we define a simplified version:
class ConvBlock(nn.Module):
    def __init__(self, in_channels, out_channels):
        super().__init__()
        self.block = nn.Sequential(
            nn.Conv2d(in_channels, out_channels, kernel_size=3, padding=1, bias=False),
            nn.BatchNorm2d(out_channels),
            nn.ReLU(inplace=True),
            nn.Conv2d(out_channels, out_channels, kernel_size=3, padding=1, bias=False),
            nn.BatchNorm2d(out_channels),
            nn.ReLU(inplace=True)
        )
    def forward(self, x):
        return self.block(x)


class SwinEncoder(nn.Module):
    """
    Swin Transformer Encoder using the timm library.
    It returns the final sequence (C4) and three intermediate skip features (C1, C2, C3).
    """
    def __init__(self, config):
        super().__init__()
        # Use timm to load the Swin model. We select a base size for demonstration.
        swin_name = config.vit_name.lower().replace('-', '_') 
        if swin_name not in ['swin_base_patch4_window7_224', 'swin_tiny_patch4_window7_224']:
             swin_name = 'swin_base_patch4_window7_224' # Default if custom name not recognized

        self.swin = timm.create_model(
            swin_name,
            pretrained=config.pretrain,
            in_chans=3,
            features_only=True, # Returns a list of feature maps from each stage
            drop_path_rate=config.drop_path_rate
        )
        
        # Swin feature channel dimensions at 1/4, 1/8, 1/16, 1/32 resolution
        # For swin_base_patch4_window7_224, channels are typically [128, 256, 512, 1024]
        self.out_channels = self.swin.feature_info.channels()
        self.encoder_embed_dim = self.out_channels[-1]

    def forward(self, x):
        # swin_features: [C1 (1/4), C2 (1/8), C3 (1/16), C4 (1/32)]
        swin_features = self.swin(x)
        
        # 1. Skip Features (C1, C2, C3)
        skip_features = swin_features[:-1]
        
        # 2. Final Deep Encoding (C4)
        final_feature_map = swin_features[-1] 

        # TransUnet Decoder expects a sequence (B, N_patches + 1, E).
        # We flatten C4 and add a dummy CLS token.
        B, C, H, W = final_feature_map.shape
        
        # Flatten and transpose: (B, C, H*W) -> (B, H*W, C)
        transformer_sequence = final_feature_map.flatten(2).transpose(1, 2) 
        
        # Add a dummy CLS token (required for TransUnetDecoder slicing x[:, 1:, :])
        dummy_cls_token = torch.zeros(B, 1, C, device=x.device)
        transformer_output = torch.cat((dummy_cls_token, transformer_sequence), dim=1)
        
        return transformer_output, skip_features 


class SwinDecoder(nn.Module):
    """
    Decoder adapted for the 4-stage hierarchical output of the Swin Encoder.
    It receives 3 skip features (C1, C2, C3) and the final sequence (C4).
    """
    def __init__(self, config, swin_channels):
        super().__init__()
        embed_dim = swin_channels[-1]  # C4 channel count (e.g., 1024)
        n_classes = config.num_classes
        
        # Swin skip channel counts: C1: 128, C2: 256, C3: 512, C4: 1024 (example)
        self.C4_ch, self.C3_ch, self.C2_ch, self.C1_ch = swin_channels[3], swin_channels[2], swin_channels[1], swin_channels[0]
        self.feat_size = config.img_size // 32 # 1/32 resolution

        # 1. Projection from flat ViT features (C4_ch) to 2D feature map
        self.proj_to_feat = nn.Conv2d(embed_dim, self.C3_ch, kernel_size=1) 
        
        # 2. UP Stage 1: 1/32 res -> 1/16 res (Concatenate C3)
        self.up_c3 = self._make_up_block(self.C3_ch, self.C3_ch // 2, self.C3_ch) 
        
        # 3. UP Stage 2: 1/16 res -> 1/8 res (Concatenate C2)
        self.up_c2 = self._make_up_block(self.C3_ch // 2, self.C2_ch // 2, self.C2_ch) 
        
        # 4. UP Stage 3: 1/8 res -> 1/4 res (Concatenate C1)
        # Note: Swin gives C1 at 1/4 res, which is used here. R50-ViT usually skips C1.
        self.up_c1 = self._make_up_block(self.C2_ch // 2, self.C1_ch // 2, self.C1_ch)

        # 5. Final UP Stage: 1/4 res -> 1/2 res (No Skip)
        self.up_final_x2 = nn.Sequential(
            nn.ConvTranspose2d(self.C1_ch // 2, 64, kernel_size=2, stride=2),
            ConvBlock(64, 64)
        )
        
        # 6. Output UP Stage: 1/2 res -> 1/1 res
        self.final_up = nn.Sequential(
            nn.ConvTranspose2d(64, 32, kernel_size=2, stride=2),
            ConvBlock(32, 32)
        )

        self.out_conv = nn.Conv2d(32, n_classes, kernel_size=1)

    def _make_up_block(self, in_channels, out_channels, skip_channels):
        # Input to ConvBlock is upsampled feature + skip feature
        return nn.Sequential(
            nn.ConvTranspose2d(in_channels, out_channels, kernel_size=2, stride=2),
            ConvBlock(out_channels + skip_channels, out_channels)
        )

    def forward(self, transformer_output, skip_features):
        # skip_features: [C1 (1/4), C2 (1/8), C3 (1/16)]
        C1, C2, C3 = skip_features[0], skip_features[1], skip_features[2]

        # 1. Reshape ViT output (C4, 1/32 res)
        # Skip CLS token (dummy token at index 0)
        x = transformer_output[:, 1:, :] 
        B, N, E = x.shape
        x = x.transpose(1, 2).view(B, E, self.feat_size, self.feat_size) 
        x = self.proj_to_feat(x) # (B, C3_ch, H/32, W/32)

        # 2. UP C3 (1/32 -> 1/16)
        up_c3_out = self.up_c3[0](x)
        x = torch.cat((up_c3_out, C3), dim=1) 
        x = self.up_c3[1](x) # (B, C3_ch//2, H/16, W/16)

        # 3. UP C2 (1/16 -> 1/8)
        up_c2_out = self.up_c2[0](x)
        x = torch.cat((up_c2_out, C2), dim=1) 
        x = self.up_c2[1](x) # (B, C2_ch//2, H/8, W/8)

        # 4. UP C1 (1/8 -> 1/4)
        up_c1_out = self.up_c1[0](x)
        x = torch.cat((up_c1_out, C1), dim=1) 
        x = self.up_c1[1](x) # (B, C1_ch//2, H/4, W/4)
        
        # 5. Final UP 1 (1/4 -> 1/2)
        x = self.up_final_x2(x) # (B, 64, H/2, W/2)
        
        # 6. Final UP 2 (1/2 -> 1/1)
        logits = self.out_conv(self.final_up(x)) 
        return logits