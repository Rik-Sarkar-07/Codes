# utils.py

import torch
import torch.nn as nn
from functools import partial

# --- Configuration Class ---

class Config:
    """Class to hold and manage all configurations."""
    def __init__(self, **kwargs):
        self.update(**kwargs)

    def update(self, **kwargs):
        for k, v in kwargs.items():
            setattr(self, k, v)

# --- DropPath Implementation (Stochastic Depth) ---

def drop_path(x, drop_prob: float = 0., training: bool = False):
    """Drop paths (Stochastic Depth) per sample."""
    if drop_prob == 0. or not training:
        return x
    keep_prob = 1 - drop_prob
    # Scale is needed to compensate for the dropped paths
    shape = (x.shape[0],) + (1,) * (x.ndim - 1)  # B, 1, 1, ...
    random_tensor = keep_prob + torch.rand(shape, dtype=x.dtype, device=x.device)
    mask = torch.floor(random_tensor).div(keep_prob)
    return x * mask

class DropPath(nn.Module):
    """Drop paths class for use in Sequential blocks."""
    def __init__(self, drop_prob=None):
        super(DropPath, self).__init__()
        self.drop_prob = drop_prob

    def forward(self, x):
        return drop_path(x, self.drop_prob, self.training)

# --- Optimizer Factory ---

def get_optimizer(model, config):
    """Returns the specified optimizer with config parameters."""
    params = filter(lambda p: p.requires_grad, model.parameters())
    
    if config.optimizer == 'sgd':
        optimizer = torch.optim.SGD(
            params, 
            lr=config.lr, 
            momentum=config.momentum, 
            weight_decay=config.weight_decay
        )
    elif config.optimizer == 'rmsprop':
        optimizer = torch.optim.RMSprop(
            params, 
            lr=config.lr, 
            momentum=config.momentum, 
            weight_decay=config.weight_decay
        )
    elif config.optimizer == 'adamw':
        optimizer = torch.optim.AdamW(
            params, 
            lr=config.lr, 
            weight_decay=config.weight_decay
        )
    else:
        raise ValueError(f"Unsupported optimizer: {config.optimizer}")
        
    return optimizer

# --- Loss Function (Placeholder for combined loss) ---

class CombinedLoss(nn.Module):
    def __init__(self):
        super().__init__()
        # In the original paper, a combination of CrossEntropyLoss and DiceLoss is often used.
        self.ce_loss = nn.CrossEntropyLoss()
        # self.dice_loss = DiceLoss() # Assuming implementation of DiceLoss
        
    def forward(self, pred, target):
        ce = self.ce_loss(pred, target)
        # dice = self.dice_loss(pred, target)
        # return 0.5 * ce + 0.5 * dice # Example weighted combination
        return ce # Return only CE for simplicity