# dataset.py

import os
from PIL import Image
from torch.utils.data import Dataset, DataLoader
from transform import get_transform

class SegmentationDataset(Dataset):
    def __init__(self, root_dir, phase='train', transform=None):
        self.transform = transform
        
        # Determine paths based on phase (train/val)
        data_type = 'train' if phase == 'train' else 'val'
        self.images_dir = os.path.join(root_dir, f'{data_type}_real', 'images')
        self.masks_dir = os.path.join(root_dir, f'{data_type}_mask', 'images')
        
        self.image_fnames = sorted([f for f in os.listdir(self.images_dir) if f.endswith(('.png', '.jpg', '.jpeg'))])
        
        if not self.image_fnames:
            raise FileNotFoundError(f"No images found in {self.images_dir}")

    def __len__(self):
        return len(self.image_fnames)

    def __getitem__(self, idx):
        img_name = self.image_fnames[idx]
        
        # Load Image (RGB)
        img_path = os.path.join(self.images_dir, img_name)
        image = Image.open(img_path).convert("RGB")
        
        # Load Mask (Grayscale)
        mask_path = os.path.join(self.masks_dir, img_name)
        mask = Image.open(mask_path).convert("L") 

        if self.transform:
            image, mask = self.transform(image, mask)
            
        return image, mask

def get_data_loaders(config, phase='train'):
    # Note: Use get_transform for both train and validation; only the batch_size/shuffle changes.
    transform = get_transform(config.img_size)
    dataset = SegmentationDataset(config.data_path, phase=phase, transform=transform)
    
    # Use different shuffle/drop_last settings for train/eval
    shuffle = True if phase == 'train' else False
    drop_last = True if phase == 'train' else False

    # In DDP mode, sampler handles shuffling
    sampler = None
    if config.distributed:
        sampler = torch.utils.data.distributed.DistributedSampler(dataset, shuffle=shuffle)
        shuffle = False # Sampler handles shuffling
        
    loader = DataLoader(
        dataset, 
        batch_size=config.batch_size, 
        shuffle=shuffle, 
        sampler=sampler,
        num_workers=config.num_workers,
        pin_memory=True
    )
    return loader, sampler