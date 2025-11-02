# model.py

import torch
import torch.nn as nn
import torch.nn.functional as F
from backbones import HybridEncoder

class ConvBlock(nn.Module):
    """Standard CNN block for the UNet decoder."""
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

class TransUnetDecoder(nn.Module):
    """Cascaded Upsampler (CUP) Decoder."""
    def __init__(self, config):
        super().__init__()
        embed_dim = config.encoder_embed_dim
        n_classes = config.num_classes
        patch_size = config.patch_size
        img_size = config.img_size
        
        self.feat_size = img_size // patch_size
        
        # Projection from flat ViT features (E_dim) to 2D feature map
        self.proj_to_feat = nn.Conv2d(embed_dim, 512, kernel_size=1) 
        
        # Skip features from ResNet: C2 (256ch), C3 (512ch)
        
        # 1. UP from ViT (1/16 res) -> 1/8 res (Concatenate C3)
        self.up_c3 = self._make_up_block(512, 256, 512) # In=512, Out=256, Skip=512
        
        # 2. UP from 1/8 res -> 1/4 res (Concatenate C2)
        self.up_c2 = self._make_up_block(256, 128, 256) # In=256, Out=128, Skip=256
        
        # 3. UP from 1/4 res -> 1/2 res (Standard UNet step)
        self.up_c1 = nn.Sequential(
            nn.ConvTranspose2d(128, 64, kernel_size=2, stride=2),
            ConvBlock(64, 64)
        )
        
        # 4. Final UP from 1/2 res -> 1/1 res
        self.final_up = nn.Sequential(
            nn.ConvTranspose2d(64, 32, kernel_size=2, stride=2),
            ConvBlock(32, 32)
        )

        self.out_conv = nn.Conv2d(32, n_classes, kernel_size=1)

    def _make_up_block(self, in_channels, out_channels, skip_channels):
        # Skip-connection concatenation is handled in the forward pass.
        # The ConvBlock input must account for Up-conv output + Skip feature channels.
        return nn.Sequential(
            nn.ConvTranspose2d(in_channels, out_channels, kernel_size=2, stride=2),
            ConvBlock(out_channels + skip_channels, out_channels)
        )

    def forward(self, transformer_output, skip_features):
        # transformer_output: (B, N_patches + 1, E). Skip CLS token.
        x = transformer_output[:, 1:, :] 
        B, N, E = x.shape
        H_p = W_p = self.feat_size
        
        # 1. Reshape ViT output to 2D feature map (1/16 res)
        x = x.transpose(1, 2).view(B, E, H_p, W_p) 
        x = self.proj_to_feat(x) # (B, 512, H/16, W/16)

        # skip_features: [C2 (1/4 res), C3 (1/8 res)]
        
        # 2. Up-Conv + Skip C3 (1/16 -> 1/8)
        up_c3_out = self.up_c3[0](x)
        # Concatenate C3 feature (skip_features[1])
        x = torch.cat((up_c3_out, skip_features[1]), dim=1) 
        x = self.up_c3[1](x) # (B, 256, H/8, W/8)

        # 3. Up-Conv + Skip C2 (1/8 -> 1/4)
        up_c2_out = self.up_c2[0](x)
        # Concatenate C2 feature (skip_features[0])
        x = torch.cat((up_c2_out, skip_features[0]), dim=1)
        x = self.up_c2[1](x) # (B, 128, H/4, W/4)
        
        # 4. Up-Conv (1/4 -> 1/2)
        x = self.up_c1(x) # (B, 64, H/2, W/2)
        
        # 5. Final Up-Conv (1/2 -> 1/1)
        x = self.final_up(x) # (B, 32, H, W)
        
        # 6. Output
        logits = self.out_conv(x) # (B, N_classes, H, W)
        return logits


class TransUnet(nn.Module):
    def __init__(self, config):
        super().__init__()
        self.encoder = HybridEncoder(config)
        self.decoder = TransUnetDecoder(config)

    def forward(self, x):
        # x: (B, 3, H, W)
        transformer_output, skip_features = self.encoder(x)
        
        # skip_features: [C2, C3]
        logits = self.decoder(transformer_output, skip_features) 
        
        return logits