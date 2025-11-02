# main.py

import argparse
import torch
import torch.distributed as dist
from torch.nn.parallel import DistributedDataParallel as DDP
import os
import sys

# Import custom modules
from model import TransUnet
from utils import Config, get_optimizer, CombinedLoss
from dataset import get_data_loaders


def parse_args():
    parser = argparse.ArgumentParser(description="TransUnet for Image Segmentation")
    
    # --- Mode and Checkpoint ---
    parser.add_argument('--mode', type=str, default='train', choices=['train', 'eval'], help='Mode: train or eval.')
    parser.add_argument('--checkpoint', type=str, default=None, help='Path to model checkpoint for eval or resume.')

    # --- Data & Training ---
    parser.add_argument('--data_path', type=str, default='./data', help='Root directory for dataset.')
    parser.add_argument('--img_size', type=int, default=224, help='Input image resolution.')
    parser.add_argument('--num_classes', type=int, default=2, help='Number of output classes.')
    parser.add_argument('--batch_size', type=int, default=16, help='Batch size per GPU.')
    parser.add_argument('--epochs', type=int, default=100, help='Number of training epochs.')
    parser.add_argument('--num_workers', type=int, default=4, help='Number of data loading workers.')

    # --- Optimization ---
    parser.add_argument('--optimizer', type=str, default='adamw', choices=['sgd', 'rmsprop', 'adamw'], help='Optimizer.')
    parser.add_argument('--lr', type=float, default=0.0001, help='Learning rate.')
    parser.add_argument('--weight_decay', type=float, default=0.01, help='Weight decay (L2 penalty).')
    parser.add_argument('--momentum', type=float, default=0.9, help='Momentum for SGD/RMSprop.')

    # --- Model Specific ---
    parser.add_argument('--vit_name', type=str, default='R50-ViT-B_16', help='ViT backbone name (R50-ViT-B_16, ViT-B_16, etc.).')
    parser.add_argument('--encoder_embed_dim', type=int, default=768, help='ViT embedding dimension.')
    parser.add_argument('--encoder_layers', type=int, default=12, help='Number of transformer layers.')
    parser.add_argument('--encoder_heads', type=int, default=12, help='Number of attention heads.')
    parser.add_argument('--drop_path_rate', type=float, default=0.1, help='Stochastic depth rate (DropPath).')
    
    # --- Pretraining Option ---
    parser.add_argument('--pretrain', action='store_true', default=False, help='Use pretrained weights.')
    parser.add_argument('--no-pretrain', dest='pretrain', action='store_false', help='Do not use pretrained weights.')
    
    # --- Distributed Training ---
    parser.add_argument('--distributed', action='store_true', default=False, help='Use PyTorch DistributedDataParallel.')
    parser.add_argument('--local_rank', type=int, default=-1, help='DDP local rank for launching script.')

    args = parser.parse_args()
    return args

# --- TRAINING AND EVALUATION FUNCTIONS ---

def train_one_epoch(model, dataloader, criterion, optimizer, device, epoch, config):
    model.train()
    dataloader.sampler.set_epoch(epoch) # For DDP shuffling
    
    if dist.is_initialized() and dist.get_rank() == 0:
        print(f"Epoch {epoch+1}/{config.epochs}")
    
    for i, (images, masks) in enumerate(dataloader):
        images, masks = images.to(device), masks.to(device)
        
        optimizer.zero_grad()
        outputs = model(images)
        loss = criterion(outputs, masks)
        
        loss.backward()
        optimizer.step()
        
        if (i+1) % 50 == 0 and (not config.distributed or dist.get_rank() == 0):
            print(f'Epoch [{epoch+1}/{config.epochs}], Step [{i+1}/{len(dataloader)}], Loss: {loss.item():.4f}')

def train_model(config):
    # DDP Setup
    if config.distributed:
        dist.init_process_group(backend='nccl')
        local_rank = dist.get_rank()
        torch.cuda.set_device(local_rank)
        device = torch.device(f"cuda:{local_rank}")
    else:
        device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    
    if not config.distributed or dist.get_rank() == 0:
        print(f"Training on device: {device} | Distributed: {config.distributed}")

    # Data
    train_loader, train_sampler = get_data_loaders(config, phase='train')
    
    # Model and Optimization
    model = TransUnet(config).to(device)
    if config.distributed:
        model = DDP(model, device_ids=[local_rank], output_device=local_rank)
    
    criterion = CombinedLoss() 
    optimizer = get_optimizer(model, config)
    
    # Training Loop
    for epoch in range(config.epochs):
        train_one_epoch(model, train_loader, criterion, optimizer, device, epoch, config)
        
        # Save Checkpoint (Only Rank 0 saves)
        if not config.distributed or dist.get_rank() == 0:
            torch.save(model.state_dict(), f'checkpoint_epoch_{epoch+1}.pth')

def evaluate_model(config):
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    print(f"Starting evaluation on device: {device}")

    # 1. Load Model and Weights
    if not config.checkpoint:
        raise ValueError("Must provide a --checkpoint path for evaluation.")

    model = TransUnet(config).to(device)
    # Load weights (handle DDP wrapper if saved from DDP training)
    state_dict = torch.load(config.checkpoint, map_location=device)
    if list(state_dict.keys())[0].startswith('module.'):
        state_dict = {k.replace('module.', ''): v for k, v in state_dict.items()}
    model.load_state_dict(state_dict)
    model.eval()
    
    # 2. Load Validation Data
    val_loader, _ = get_data_loaders(config, phase='val') 
    
    # 3. Evaluation Loop (Dice Metric Placeholder)
    total_dice = 0.0
    total_samples = 0
    
    with torch.no_grad():
        for images, masks in val_loader:
            images, masks = images.to(device), masks.to(device)
            outputs = model(images)
            preds = torch.argmax(outputs, dim=1)
            
            # --- METRIC CALCULATION PLACEHOLDER ---
            # Replace this with your actual metric calculation (e.g., Multi-class Dice, IoU)
            # Example: total_dice += calculate_dice(preds, masks, config.num_classes) * images.size(0)
            total_dice += 0.85 * images.size(0) # Dummy score
            # -------------------------------------
            
            total_samples += images.size(0)

    avg_dice = total_dice / total_samples
    print("\n--- Evaluation Results ---")
    print(f"Total Validation Images: {total_samples}")
    print(f"Average Dice Score: {avg_dice:.4f}")


# --- MAIN EXECUTION BLOCK ---

if __name__ == '__main__':
    args = parse_args()
    final_config = Config(**vars(args))
    
    if final_config.mode == 'train':
        if final_config.distributed:
            # Command to launch DDP: python -m torch.distributed.launch --nproc_per_node=NUM_GPUS main.py ...
            # The local_rank is handled by the launch utility
            train_model(final_config)
        else:
            train_model(final_config)
    elif final_config.mode == 'eval':
        evaluate_model(final_config)
    
    if final_config.distributed and dist.is_initialized():
        dist.destroy_process_group()