#!/usr/bin/env python3

import torch


def main():
    left_context = 0
    N = 1
    T = 1
    H = 5  # time1
    W = 2 * H - 1 + left_context  # 2time1 - 1 + left_context
    a = torch.randn(N, T, H, W)
    a = torch.arange(N * T * H * W).reshape(N, T, H, W).contiguous()

    if True:
        rows = torch.arange(start=H - 1, end=-1, step=-1).unsqueeze(-1)
        cols = torch.arange(H + left_context)
        indexes = rows + cols

        indexes = torch.tile(indexes, (N * T, 1))
    else:
        rows = torch.arange(start=H - 1, end=-1, step=-1)
        cols = torch.arange(H + left_context)
        rows = torch.cat([rows] * (N * T)).unsqueeze(-1)
        indexes = rows + cols

    print(indexes.shape)

    ta = a.reshape(-1, W)

    b = torch.gather(ta, dim=1, index=indexes)
    b = b.reshape(N, T, H, -1)

    c = a.as_strided(
        (N, T, H, H + left_context),
        (T * H * W, H * W, W - 1, 1),
        storage_offset=H - 1,
    )
    assert torch.equal(b, c), (b, c)


if __name__ == "__main__":
    torch.manual_seed(20220727)
    main()
