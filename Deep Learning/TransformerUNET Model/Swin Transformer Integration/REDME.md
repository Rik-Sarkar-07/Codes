
# 🧱 Swin Transformer Encoder Integration Guide (Swin-Unet Hybrid)

This guide provides the precise steps to switch the project's encoder from the original $\text{R50}$-$\text{ViT}$ hybrid to the hierarchical **Swin Transformer** (Swin-Unet hybrid).

## 🛠️ 1. Prerequisites and New File

### A. Dependencies

Ensure you have the `timm` library installed:

```bash
pip install timm
```

### B. New File

Create a new file named **`swin_integration.py`** and place the `SwinEncoder` and `SwinDecoder` classes inside it. The code for this file contains the model logic to handle the four-stage hierarchical output of the Swin Transformer.

-----

## 2\. Integration Steps: Code Changes

You must modify **three** files to enable the Swin-Unet hybrid.

### A. Modify `swin_integration.py`

*(This file contains the complete `SwinEncoder` and the adapted `SwinDecoder` classes.)*

### B. Modify `model.py` (The Switch Logic)

Update the `TransUnet` class to dynamically select the correct encoder and decoder based on the `config.vit_name` argument.

| Action | Location | Detail |
| :--- | :--- | :--- |
| **Import Swin classes** | Top of `model.py` | Import `SwinEncoder` and `SwinDecoder` from `swin_integration`. |
| **Switch Logic** | `TransUnet.__init__` | Implement an `if/else` block to check if `'Swin'` is in `config.vit_name` and instantiate the corresponding `SwinEncoder`/`SwinDecoder`. |

### C. Modify `main.py` (The Configuration Flag)

Ensure your primary script is ready to accept the Swin flag.

| Action | Location | Detail |
| :--- | :--- | :--- |
| **Update Argument** | `main.py` -\> `parse_args` | Ensure the help string for `--vit_name` mentions Swin models (e.g., `Swin-B`). |

-----

## 🏃 3. Training Scripts (Swin-Unet Hybrid)

Once the integration is complete, you can launch training using the `main.py` script by specifying a Swin backbone name (e.g., `Swin-B`) using the `--vit_name` argument.

### A. Standard Training (Single GPU/CPU)

```bash
# Example: Train the Swin-Unet Hybrid (Swin-Base model)
python main.py --mode train --vit_name Swin-B --lr 0.00006 --epochs 100 --drop_path_rate 0.2 --pretrain
```

### B. Distributed Training (Multi-GPU DDP)

Use PyTorch's launch utility for multi-GPU efficiency:

```bash
# Example: Launch training across 4 GPUs
python -m torch.distributed.launch --nproc_per_node=4 main.py --distributed --vit_name Swin-B --lr 0.00006 --batch_size 4
```