#!/usr/bin/env python3

import torch
import torch.nn as nn


class Foo(nn.Module):
    def __init__(self, i):
        super().__init__()
        self.relu = nn.ReLU()
        self.i = 1

    def forward(self, x):
        if x.sum().item() > 0:
            return self.relu(x + 1)
        else:
            return self.relu(x + 2)


def main():
    f = Foo(1)
    f.eval()  # f.train(False)
    f = torch.jit.script(f)

    x = torch.rand(2, 3, 4)
    # [N, T, C]
    torch.onnx.export(
        f,
        x,
        "f.onnx",
        verbose=False,
        input_names=["x"],
        output_names=["y"],
        dynamic_axes={"x": {0: "batch_size", 1: "T"}, "y": [0, 1]},
        #  dynamic_axes={"x": [0, 1], "y": [0, 1]},
    )


if __name__ == "__main__":
    main()
