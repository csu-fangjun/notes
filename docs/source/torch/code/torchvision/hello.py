#!/usr/bin/env python3

import torch
from torchvision.transforms import v2


def test_crop():
    H, W = 8, 8
    img = torch.randint(0, 256, size=(3, H, W), dtype=torch.uint8)
    print(img)
    transform = v2.RandomCrop(size=(3, 3))
    print(transform)
    img2 = transform(img)
    print("----------")
    print(img2)


def main():
    test_crop()


if __name__ == "__main__":
    torch.manual_seed(20240606)
    main()
