#!/usr/bin/env python3

import torch


# https://pytorch.org/docs/stable/generated/torch.quantize_per_tensor.html
def test_quantize_per_tensor():
    scale = 0.1
    zero_point = 1
    a = torch.tensor([10.0, 2.0], dtype=torch.float32)
    b = torch.quantize_per_tensor(
        input=a,
        scale=scale,
        zero_point=zero_point,
        dtype=torch.qint8,
    )
    assert isinstance(b, torch.Tensor)
    assert b.is_quantized is True

    assert b.q_scale() == scale
    assert b.q_zero_point() == zero_point
    assert str(b.qscheme()) == "torch.per_tensor_affine"
    assert b.dtype == torch.qint8

    c = b.int_repr()
    assert c[0] == a[0] / scale + zero_point
    assert c[1] == a[1] / scale + zero_point
    assert torch.all(torch.eq(c, torch.tensor([101, 21], dtype=torch.int8)))


def main():
    test_quantize_per_tensor()


if __name__ == "__main__":
    main()
