# backbones.py

import torch
import torch.nn as nn
from utils import DropPath

# --- 1. Core Transformer Blocks ---

class Mlp(nn.Module):
    def __init__(self, in_features, hidden_features=None, out_features=None, drop=0.):
        super().__init__()
        out_features = out_features or in_features
        hidden_features = hidden_features or in_features
        self.fc1 = nn.Linear(in_features, hidden_features)
        self.act = nn.GELU()
        self.fc2 = nn.Linear(hidden_features, out_features)
        self.drop = nn.Dropout(drop)

    def forward(self, x):
        x = self.fc1(x)
        x = self.act(x)
        x = self.drop(x)
        x = self.fc2(x)
        x = self.drop(x)
        return x

class Attention(nn.Module):
    def __init__(self, dim, num_heads=8, qkv_bias=False, attn_drop=0., proj_drop=0.):
        super().__init__()
        self.num_heads = num_heads
        head_dim = dim // num_heads
        self.scale = head_dim ** -0.5

        self.qkv = nn.Linear(dim, dim * 3, bias=qkv_bias)
        self.attn_drop = nn.Dropout(attn_drop)
        self.proj = nn.Linear(dim, dim)
        self.proj_drop = nn.Dropout(proj_drop)

    def forward(self, x):
        B, N, C = x.shape
        qkv = self.qkv(x).reshape(B, N, 3, self.num_heads, C // self.num_heads).permute(2, 0, 3, 1, 4)
        q, k, v = qkv[0], qkv[1], qkv[2]  # B, num_heads, N, C // num_heads

        attn = (q @ k.transpose(-2, -1)) * self.scale
        attn = attn.softmax(dim=-1)
        attn = self.attn_drop(attn)

        x = (attn @ v).transpose(1, 2).reshape(B, N, C)
        x = self.proj(x)
        x = self.proj_drop(x)
        return x

class Block(nn.Module):
    """Single Transformer Encoder Block with DropPath"""
    def __init__(self, dim, num_heads, mlp_ratio=4., qkv_bias=False, drop=0., attn_drop=0., drop_path=0.):
        super().__init__()
        self.norm1 = nn.LayerNorm(dim)
        self.attn = Attention(dim, num_heads=num_heads, qkv_bias=qkv_bias, attn_drop=attn_drop, proj_drop=drop)
        self.drop_path = DropPath(drop_path) if drop_path > 0. else nn.Identity()
        self.norm2 = nn.LayerNorm(dim)
        mlp_hidden_dim = int(dim * mlp_ratio)
        self.mlp = Mlp(in_features=dim, hidden_features=mlp_hidden_dim, drop=drop)

    def forward(self, x):
        x = x + self.drop_path(self.attn(self.norm1(x)))
        x = x + self.drop_path(self.mlp(self.norm2(x)))
        return x

# --- 2. ViT Encoder (Transformer Core) ---

class ViTEncoder(nn.Module):
    def __init__(self, config, drop_path_rate=0.1):
        super().__init__()
        self.embed_dim = config.encoder_embed_dim
        
        # Stochastic Depth (DropPath) scheduling
        dpr = [x.item() for x in torch.linspace(0, drop_path_rate, config.encoder_layers)]
        
        # Simplified Patch/Positional Embedding logic
        num_patches = (config.img_size // config.patch_size) ** 2
        self.cls_token = nn.Parameter(torch.zeros(1, 1, self.embed_dim))
        self.pos_embed = nn.Parameter(torch.zeros(1, num_patches + 1, self.embed_dim))
        
        # Transformer Blocks
        self.blocks = nn.ModuleList([
            Block(
                dim=self.embed_dim, 
                num_heads=config.encoder_heads, 
                mlp_ratio=4., 
                qkv_bias=True, 
                drop=0., 
                attn_drop=0., 
                drop_path=dpr[i]
            )
            for i in range(config.encoder_layers)
        ])
        self.norm = nn.LayerNorm(self.embed_dim)
        
    def forward(self, x_tokens):
        # x_tokens: (B, N_patches, E)
        B = x_tokens.shape[0]
        
        cls_tokens = self.cls_token.expand(B, -1, -1)
        x = torch.cat((cls_tokens, x_tokens), dim=1)
        x = x + self.pos_embed # Add positional embedding

        for blk in self.blocks:
            x = blk(x)
        
        x = self.norm(x)
        return x # (B, N_patches + 1, E)

# --- 3. CNN Feature Extractor (ResNet-50 part for Hybrid Encoder) ---

class ResNetV2(nn.Module):
    """
    Placeholder for the ResNet-50 Feature Extractor (4 stages).
    The ResNet extracts features for both tokenization and skip connections.
    """
    def __init__(self):
        super().__init__()
        # Skip channel sizes for R50-ViT:
        # C2: 256 (1/4 res) -> Skip 1
        # C3: 512 (1/8 res) -> Skip 2
        # C4: 1024 (1/16 res) -> Input to ViT tokenization
        
        self.layer1 = nn.Identity() # C1 (1/2 res, ignored for typical R50-ViT skip)
        self.layer2 = nn.Identity() # C2: 1/4 resolution feature map
        self.layer3 = nn.Identity() # C3: 1/8 resolution feature map
        self.layer4 = nn.Identity() # C4: 1/16 resolution feature map (Input to ViT)

        # Tokenization part
        # TransUNet tokenizes the C4 feature map (1/16 res)
        self.conv_proj = nn.Conv2d(1024, 768, kernel_size=1) # 1x1 conv to project C4 to E_dim

    def forward(self, x):
        # Note: In a real model, x is passed through 4 ResNet stages
        
        # Mock features to match expected shapes/channels:
        feat_c2 = torch.rand(x.shape[0], 256, x.shape[2]//4, x.shape[3]//4, device=x.device)
        feat_c3 = torch.rand(x.shape[0], 512, x.shape[2]//8, x.shape[3]//8, device=x.device)
        feat_c4 = torch.rand(x.shape[0], 1024, x.shape[2]//16, x.shape[3]//16, device=x.device)
        
        # 1. Skip connections for Decoder
        skip_features = [feat_c2, feat_c3] # C2 (1/4), C3 (1/8)
        
        # 2. Input for ViT
        feat_c4_proj = self.conv_proj(feat_c4) # (B, E_dim, H/16, W/16)
        
        # Flatten and transpose for Transformer input sequence
        B, C, H, W = feat_c4_proj.shape
        vit_input_tokens = feat_c4_proj.flatten(2).transpose(1, 2) # (B, N_patches, E_dim)
        
        return vit_input_tokens, skip_features

# --- 4. Hybrid Encoder ---

class HybridEncoder(nn.Module):
    """
    The full R50-ViT-B_16 Hybrid Encoder.
    It encapsulates the CNN feature extractor and the ViT encoder.
    """
    def __init__(self, config):
        super().__init__()
        self.cnn_extractor = ResNetV2()
        self.vit_encoder = ViTEncoder(config, drop_path_rate=config.drop_path_rate)

    def forward(self, x):
        # 1. CNN extraction (C4 feature map and skip features)
        vit_input_tokens, skip_features = self.cnn_extractor(x)
        
        # 2. ViT encoding (Adds CLS token, position embedding, and runs blocks)
        transformer_output = self.vit_encoder(vit_input_tokens)
        
        # transformer_output: (B, N_patches + 1, E)
        # skip_features: [C2 (1/4 res), C3 (1/8 res)]
        return transformer_output, skip_features