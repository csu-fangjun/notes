#!/usr/bin/env python3
import torch
import torch.nn as nn


@torch.no_grad()
def main():
    input_size = 3
    hidden_size = 5
    proj_size = 2
    num_layers = 1
    lstm = nn.LSTM(
        input_size=input_size,
        hidden_size=hidden_size,
        num_layers=num_layers,
        bias=True,
        proj_size=proj_size,
        batch_first=True,
    )
    L = 3
    N = 2
    x = torch.rand(N, L, input_size)
    h0 = torch.rand(num_layers, N, proj_size)
    c0 = torch.rand(num_layers, N, hidden_size)

    y, (h1, c1) = lstm(x, (h0, c0))
    print(y, h1, c1)

    print("---")

    y00, (h10, c10) = lstm(x[0:1, :], (h0[:, 0:1, :], c0[:, 0:1, :]))
    print(y00, h10, c10)

    y01, (h11, c11) = lstm(x[1:2, :2], (h0[:, 1:2, :], c0[:, 1:2, :]))
    print(y01, h11, c11)


if __name__ == "__main__":
    torch.manual_seed(20230423)
    main()
