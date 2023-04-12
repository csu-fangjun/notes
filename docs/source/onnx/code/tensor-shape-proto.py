#!/usr/bin/env python3
import onnx
import numpy as np


def main():
    shape_proto = onnx.TensorShapeProto()

    # shape_proto.dim is a list of messages, so we need to use add()
    dim = shape_proto.dim.add()
    dim.dim_value = 10

    dim2 = shape_proto.dim.add()
    dim2.dim_param = "N"
    print(shape_proto)
    """
    dim {
      dim_value: 10
    }
    dim {
      dim_param: "N"
    }
    """

    # Only one of dim_value and dim_param can be set
    for d in shape_proto.dim:
        which = d.WhichOneof("value")
        if which == "dim_value":
            print(d.dim_value)  # 10
        elif which == "dim_param":
            print(d.dim_param)  # N
        else:
            assert which is None


if __name__ == "__main__":
    main()
