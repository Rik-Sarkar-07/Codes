# model.py (Changes)

import torch.nn as nn
# ... (Other imports: ConvBlock, HybridEncoder, TransUnetDecoder)
from swin_integration import SwinEncoder, SwinDecoder # <-- NEW IMPORT

class TransUnet(nn.Module):
    def __init__(self, config):
        super().__init__()
        
        # --- ENCODER/DECODER SELECTION LOGIC ---
        if 'Swin' in config.vit_name:
            print(f"Using Swin-Unet Hybrid with {config.vit_name}")
            self.encoder = SwinEncoder(config)
            
            # Use Swin's output channel info to configure the decoder
            swin_channels = self.encoder.out_channels
            self.decoder = SwinDecoder(config, swin_channels=swin_channels)
            
        else:
            print(f"Using standard R50-ViT Hybrid with {config.vit_name}")
            # Ensure HybridEncoder and TransUnetDecoder are imported from your original files
            from backbones import HybridEncoder # Assuming you kept HybridEncoder here or in backbones.py
            self.encoder = HybridEncoder(config)
            self.decoder = TransUnetDecoder(config) # Original Decoder
            
    def forward(self, x):
        transformer_output, skip_features = self.encoder(x)
        logits = self.decoder(transformer_output, skip_features) 
        return logits