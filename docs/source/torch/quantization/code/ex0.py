#!/usr/bin/env python3

import torch
import os


# https://pytorch.org/docs/stable/generated/torch.quantize_per_tensor.html
def test_quantize_per_tensor():
    scale = 0.1
    zero_point = 1
    a = torch.tensor([10.0, 2.0], dtype=torch.float32)
    q = torch.quantize_per_tensor(
        input=a,
        scale=scale,
        zero_point=zero_point,
        dtype=torch.qint8,
    )
    assert isinstance(q, torch.Tensor)
    assert q.is_quantized is True

    assert q.q_scale() == scale
    assert q.q_zero_point() == zero_point
    assert str(q.qscheme()) == "torch.per_tensor_affine"
    assert q.dtype == torch.qint8

    c = q.int_repr()
    assert c[0] == a[0] / scale + zero_point
    assert c[1] == a[1] / scale + zero_point
    assert torch.all(torch.eq(c, torch.tensor([101, 21], dtype=torch.int8)))
    d = q.dequantize()
    assert d.dtype == torch.float32
    assert torch.all(torch.eq(d, a))

    f = torch.dequantize(q)
    assert torch.all(torch.eq(f, a))
    #  print(q)
    """
    tensor([10.,  2.], size=(2,), dtype=torch.qint8,
           quantization_scheme=torch.per_tensor_affine, scale=0.1, zero_point=1)
    """
    assert q[0].item() == 10  # q[0].item() will dequantize() to a float
    assert q[1].item() == 2
    print(type(q[0].item()))
    q[0] = 2.5  # Note: it will quantize 2.5 and store it in q
    print(q.int_repr())
    """
    tensor([26, 21], dtype=torch.int8)
    """


def test_quantize_per_channel_2d():
    # (N, C)
    a = torch.tensor(
        [
            [1, 2, 3],
            [4, 5, 6],
        ],
        dtype=torch.float32,
    )
    assert a.shape == (2, 3)
    scales = torch.tensor([0.125, 0.25, 0.5])

    # It will be converted to torch.int64 internally
    zero_points = torch.tensor([10, 20, 30], dtype=torch.int32)
    q = torch.quantize_per_channel(
        input=a,
        scales=scales,
        zero_points=zero_points,
        axis=1,
        dtype=torch.qint8,
    )
    assert q.dtype == torch.qint8

    assert q.q_per_channel_scales().dtype == torch.float64
    assert torch.all(torch.eq(q.q_per_channel_scales(), scales))

    assert q.q_per_channel_zero_points().dtype == torch.int64
    assert torch.all(torch.eq(q.q_per_channel_zero_points(), zero_points))

    assert str(q.qscheme()) == "torch.per_channel_affine"

    assert q.q_per_channel_axis() == 1

    i = q.int_repr()
    expected_i = torch.tensor([[18, 28, 36], [42, 40, 42]], dtype=torch.int8)
    assert i.dtype == torch.int8
    assert torch.all(torch.eq(i, expected_i))

    assert i[0][0].item() == a[0][0].item() / scales[0] + zero_points[0]
    assert i[0][1].item() == a[0][1].item() / scales[1] + zero_points[1]
    assert i[0][2].item() == a[0][2].item() / scales[2] + zero_points[2]

    assert i[1][0].item() == a[1][0].item() / scales[0] + zero_points[0]
    assert i[1][1].item() == a[1][1].item() / scales[1] + zero_points[1]
    assert i[1][2].item() == a[1][2].item() / scales[2] + zero_points[2]

    d = q.dequantize()
    assert torch.all(torch.eq(d, a))

    f = torch.dequantize(q)
    assert torch.all(torch.eq(f, a))

    #  print(q)
    """
    tensor([[1., 2., 3.],
            [4., 5., 6.]], size=(2, 3), dtype=torch.qint8,
           quantization_scheme=torch.per_channel_affine,
           scale=tensor([0.1250, 0.2500, 0.5000], dtype=torch.float64),
           zero_point=tensor([10, 20, 30]), axis=1)
    """


def test_size():
    r = torch.rand(100, 100, dtype=torch.float32)
    q = torch.quantize_per_tensor(r, scale=0.1, zero_point=0, dtype=torch.qint8)
    torch.save(r, "float32.pt")
    torch.save(q, "int8.pt")
    float_size = os.path.getsize("float32.pt")
    int8_size = os.path.getsize("int8.pt")
    print("float_size:", float_size)
    print("int8_size:", int8_size)
    print(f"ratio: {float_size}/{int8_size}: {float_size/int8_size:.3f}")
    os.remove("float32.pt")
    os.remove("int8.pt")
    """
    float_size: 40747
    int8_size: 10795
    ratio: 40747/10795: 3.775
    """


def main():
    test_quantize_per_tensor()
    test_quantize_per_channel_2d()
    test_size()


if __name__ == "__main__":
    main()
