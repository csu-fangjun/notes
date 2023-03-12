#!/usr/bin/env python3
import numpy as np


def test_attr():
    a = np.array([[1, 2], [3, 4]], dtype=np.float32)
    assert isinstance(a, np.ndarray)

    assert a.dtype == np.float32
    assert isinstance(a.dtype, np.dtype)
    assert a.dtype.name == "float32"

    # number of axes
    assert a.ndim == 2

    assert a.shape == (2, 2)
    assert len(a.shape) == a.ndim

    # total number of elements is a.size
    assert a.size == a.shape[0] * a.shape[1]

    # each float occupies 4 bytes
    assert a.itemsize == 4
    assert isinstance(a.data, memoryview)


def test_array_creation():
    a = np.array([2, 3, 4])
    assert a.dtype == np.int64
    assert a.ndim == 1

    b = np.array([2.0, 3, 4])
    assert b.dtype == np.float64

    c = np.array([[1, 2], [3, 4]])
    assert c.ndim == 2
    assert c.shape == (2, 2)
    assert c.dtype == np.int64

    d = np.zeros((2, 3))
    assert d.dtype == np.float64
    assert d.shape == (2, 3)

    f = np.ones((2, 2))
    assert f.dtype == np.float64

    # uninitialized content; containing garbage data.
    e = np.empty((5, 5))
    assert e.dtype == np.float64

    g = np.empty((1, 2), dtype=np.int32)
    assert g.dtype == np.int32


def main():
    test_attr()
    test_array_creation()


if __name__ == "__main__":
    main()
