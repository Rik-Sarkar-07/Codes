```markdown
# 📖 TransUNet Segmentation Project

This repository contains a flexible PyTorch implementation of the **TransUNet** architecture for image segmentation. It features a hybrid CNN-Transformer encoder (R50-ViT), a UNet-style decoder, and robust training capabilities including support for multiple optimizers, **DropPath** regularization, and **Distributed Data Parallel (DDP)**.

---

## 🚀 1. Features

* **Model:** TransUNet (Hybrid ResNet-ViT Encoder + UNet Decoder).
* **Backbone:** Configurable encoder details (embedding dimension, layers, heads).
* **Regularization:** Includes **DropPath (Stochastic Depth)** for ViT regularization.
* **Optimizers:** Supports **AdamW** (default), **RMSprop**, and **SGD** with weight decay/momentum.
* **Training:** Full support for single-GPU and multi-GPU training via **PyTorch DDP** (`--distributed`).
* **Modes:** Dedicated **`train`** and **`eval`** modes.

---

## 📁 2. Project Structure

The project is structured as follows:

```
transunet_project/
├── main.py                 # Entry point, argument parsing, DDP setup, train/eval loop
├── model.py                # The TransUnet model definition
├── backbones.py            # ViT, ResNet components, and core Transformer blocks (with DropPath)
├── dataset.py              # PyTorch Dataset and DataLoader logic
├── transform.py            # Coordinated image and mask augmentation
├── utils.py                # Configuration, optimizers, and loss functions
├── swin_integration.py     # NEW: Code for Swin Transformer backbone integration
└── README.md               # This file
```

---

## 📦 3. Installation and Setup

### Prerequisites

* Python 3.8+
* NVIDIA GPUs (for fast training and DDP)

### Dependencies

Install the necessary Python packages, including `timm` for easy access to the Swin Transformer:

```bash
pip install torch torchvision numpy tqdm pillow scipy timm
```

---

## 🗂️ 4. Dataset Structure

### Example: Root Directory (`--data_path ./data`)

```
./data/
├── train_real/
│   └── images/
│       ├── image_001.png
│       └── ...
├── train_mask/
│   └── images/
│       ├── image_001.png  # Mask file (single-channel 0-255 grayscale)
│       └── ...
├── val_real/
│   └── images/
│       ├── image_a.png
│       └── ...
└── val_mask/
    └── images/
        ├── image_a.png
        └── ...
```

---

## ⚙️ 5. Training and Evaluation Scripts

The `main.py` script orchestrates all functionality. Use the `--mode` flag to switch between training and evaluation.

### 5.1 Training Mode (`--mode train`)

| Argument          | Description                                      | Default     |
|-------------------|--------------------------------------------------|-------------|
| `--data_path`     | Root directory of the dataset                    | `../data`   |
| `--epochs`        | Number of training epochs                        | `100`       |
| `--batch_size`    | Batch size per GPU                               | `16`        |
| `--lr`            | Initial learning rate                            | `0.0001`    |
| `--optimizer`     | Optimization algorithm. Choices: `adamw`, `sgd`, `rmsprop` | `adamw` |
| `--drop_path_rate`| Stochastic depth rate for ViT blocks             | `0.1`       |
| `--pretrain`      | Use pretrained weights for the backbone          | `False`     |

#### A. Single-GPU Training (R50-ViT Hybrid)

```bash
# Train R50-ViT with AdamW, pretrained weights, and DropPath
python main.py --mode train --lr 0.0001 --epochs 100 --drop_path_rate 0.1 --pretrain
```

#### B. Distributed Training (DDP)

```bash
# Launch training across 4 GPUs
python -m torch.distributed.launch --nproc_per_node=4 main.py --distributed --lr 0.0001 --batch_size 4 --epochs 50
```

### 5.2 Evaluation Mode (`--mode eval`)

```bash
# Evaluate the model saved after 50 epochs
python main.py --mode eval --checkpoint ./checkpoint_epoch_50.pth --data_path ./data
```

---

## 🧱 6. Integrating Swin Transformer (Swin-Unet Hybrid)

The hierarchical nature of Swin Transformer makes it a powerful replacement for the standard ResNet-ViT encoder. Use the code in `swin_integration.py` to perform this switch.

### Integration Steps

1. **Modify `main.py`:** Update the configuration logic to recognize the new Swin backbone name (e.g., set `vit_name='Swin-B'`).

2. **Integrate `swin_integration.py`:** 
   - Copy the `SwinEncoder` class from `swin_integration.py` into your `backbones.py` file.
   - Add `import timm` to the top of `backbones.py`.

3. **Update `model.py`:** Change the `TransUnet` constructor to use the `SwinEncoder` when the configuration flag is set.

4. **Update Decoder Logic:** The `TransUnetDecoder` in `model.py` must be adjusted to correctly handle the four skip connections (C1, C2, C3, C4) provided by the hierarchical Swin Encoder, instead of just the two (C2, C3) from the R50-ViT hybrid.

### Command for Training Swin-Unet

Assuming you've updated `model.py` to use `SwinEncoder` when `--vit_name Swin-B` is passed:

```bash
# Train the Swin-Unet Hybrid (Swin-B is the vit_name flag)
python main.py --mode train --vit_name Swin-B --lr 0.00006 --epochs 100 --drop_path_rate 0.2
```
```