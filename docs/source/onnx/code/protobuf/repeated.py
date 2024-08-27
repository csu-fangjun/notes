#!/usr/bin/env python3

import onnx

# Works as a python list, but it is not a Python list


def test1():
    n = onnx.NodeProto()
    assert len(n.input) == 0, len(n.input)
    n.input.append("i0")
    n.input.append("i1")

    n.input.extend(["i2", "i3"])
    print(n)
    """
    input: "i0"
    input: "i1"
    input: "i2"
    input: "i3"
    """

    assert len(n.input) == 4
    assert n.input[0] == "i0"
    assert n.input[1] == "i1"
    assert n.input[2] == "i2"
    assert n.input[3] == "i3"

    del n.input[0]
    assert len(n.input) == 3
    assert n.input == ["i1", "i2", "i3"], n.input

    # There are at least 3 methods to clear a repeated fields

    # Method 1: Use ClearField()

    n.ClearField("input")
    assert len(n.input) == 0

    # Method 2: Use del
    n.input.append("ii")
    assert len(n.input) == 1
    del n.input[:]

    assert len(n.input) == 0

    # Method 3, use pop
    n.input.append("1")
    n.input.append("2")
    n.input.extend(["3", "4", "5"])

    while len(n.input) > 0:
        n.input.pop()

    assert len(n.input) == 0

    # Method 4
    n.input.append("10")
    assert len(n.input) == 1
    n.input[:] = []
    assert len(n.input) == 0


def test2():
    s = onnx.TensorShapeProto()
    assert len(s.dim) == 0, len(s.dim)

    d = s.dim.add()
    assert id(d) == id(s.dim[0]), (id(d), id(s.dim[0]))

    d.dim_value = 1

    p = s.dim.add()
    p.dim_param = "N"

    # Copy an existing one
    k = onnx.TensorShapeProto.Dimension()
    k.dim_value = 10

    s.dim.append(k)
    assert s.dim[2] == k, (s.dim[2], k)

    # It is a copy, so id is different
    assert id(s.dim[2]) != id(k), (id(s.dim[2]), id(k))

    print(s)
    """
    dim {
      dim_value: 1
    }
    dim {
      dim_param: "N"
    }
    dim {
      dim_value: 10
    }
    """


def main():
    test1()
    test2()


if __name__ == "__main__":
    main()
