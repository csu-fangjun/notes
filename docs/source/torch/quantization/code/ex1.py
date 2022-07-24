#!/usr/bin/env python3

import torch
import torch.nn as nn


class Model(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.fc = nn.Linear(1, 1)

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
    print(model_int8.fc)
    assert model_int8.fc.weight().is_quantized
    assert model_int8.fc.weight().dtype == torch.qint8

    assert model_int8.fc.bias().is_quantized is False
    assert model_int8.fc.bias().dtype == torch.float32

    x = torch.tensor([[1.0]], dtype=torch.float32)
    y = m(x)
    print(x, y)  # tensor([[1.]]) tensor([[-1.2900]], grad_fn=<AddmmBackward0>)

    qy = model_int8(x)
    print(qy)  # tensor([[-1.2931]])


if __name__ == "__main__":
    torch.manual_seed(20220723)
    main()
