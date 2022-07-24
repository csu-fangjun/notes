#!/usr/bin/env python3

import torch
from torch.ao.quantization.observer import _with_args, MinMaxObserver


class Foo:
    def __init__(self, a=1, b=2):
        self.a = a
        self.b = b


def test_with_args():
    Foo.with_args = classmethod(_with_args)
    foo_builder = Foo.with_args(a=3).with_args(b=4).with_args(a=10)
    f = foo_builder()
    assert f.a == 10  # the last a=10 replaces the first a=3
    assert f.b == 4

    f2 = foo_builder()
    assert id(f) != id(f2)


def test_min_max_observer():
    ob = MinMaxObserver(dtype=torch.qint8)
    print(ob)  # MinMaxObserver(min_val=inf, max_val=-inf)

    ob(torch.tensor([1, 2, 3]))
    print(ob)  # MinMaxObserver(min_val=1.0, max_val=3.0)

    ob(torch.tensor([-1, 30]))
    print(ob)  # MinMaxObserver(min_val=-1.0, max_val=30.0)
    scale, zero_point = ob.calculate_qparams()
    print("scale", scale)  # scale tensor([0.1216])
    print("zero_point", zero_point)  # zero_point tensor([-120], dtype=torch.int32)


def main():
    test_with_args()
    test_min_max_observer()


if __name__ == "__main__":
    main()
