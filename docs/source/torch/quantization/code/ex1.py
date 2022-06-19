#!/usr/bin/env python3

import torch
import torch.nn as nn


class Model(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.fc = nn.Linear(2, 2)

    def forward(self, x):
        x = self.fc(x)
        return x


def main():
    m = Model()
    model_int8 = torch.quantization.quantize_dynamic(
        model=m,
        qconfig_spec={torch.nn.Linear},
        dtype=torch.qint8,
    )
    print(model_int8)


if __name__ == "__main__":
    main()
