# main.py (Changes in parse_args function)

    # --- Model Specific ---
    parser.add_argument('--vit_name', type=str, 
                        default='R50-ViT-B_16', # Original Default
                        help='ViT backbone name (R50-ViT-B_16, Swin-B, etc.).')
    # ... (Other arguments remain unchanged)