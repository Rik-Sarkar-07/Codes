# transform.py

import torchvision.transforms as T
from PIL import Image
import torch
import numpy as np
import random

class JointTransform:
    """Applies random transformations identically to image and mask."""
    def __init__(self, img_size):
        self.img_size = img_size
        self.resize = T.Resize((img_size, img_size), interpolation=T.InterpolationMode.BILINEAR)
        
    def __call__(self, image: Image.Image, mask: Image.Image):
        # 1. Resize (Must be done first to ensure consistent size)
        image = self.resize(image)
        mask = self.resize(mask)
        
        # Random Flip (Coordinated)
        if random.random() > 0.5:
            image = T.functional.hflip(image)
            mask = T.functional.hflip(mask)
            
        # Random Rotation (PIL operation)
        angle = random.choice([0, 90, 180, 270])
        if angle != 0:
            image = image.rotate(angle, resample=Image.Resampling.BILINEAR)
            mask = mask.rotate(angle, resample=Image.Resampling.NEAREST) # NEAREST for mask to preserve labels
            
        # Convert to Tensor and Normalize
        image = T.ToTensor()(image)
        image = T.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])(image)
        
        # Convert mask to Tensor (L channel), scale to 0/1/C-ID, and ensure Long type
        mask = T.ToTensor()(mask)
        # Assuming masks are single-channel grayscale (0-255). Convert to class indices.
        mask = (mask * 255).long().squeeze(0) 
        
        return image, mask

def get_transform(img_size):
    return JointTransform(img_size)