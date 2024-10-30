#!/usr/bin/env python3

import torch


class MyModel(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.layer = torch.nn.Linear(2, 2)

    def forward(self, x, num_steps: torch.Tensor):
        for i in range(num_steps):
            x = self.layer(x)

        return x


@torch.inference_mode()
def main():
    m = MyModel()
    x = torch.rand(2, 2)

    y1 = m(x, torch.tensor([1]))
    print(y1)

    y2 = m(x, torch.tensor([2]))
    print(y2)

    y3 = m(x, torch.tensor([3]))
    print(y3)

    step = torch.tensor([3])
    w = torch.onnx.dynamo_export(m, x, step)


if __name__ == "__main__":
    torch.manual_seed(20241122)
    main()
