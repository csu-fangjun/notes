#!/usr/bin/env python3
import onnx
import numpy as np


def main():
    x = onnx.helper.make_tensor_value_info(
        name="X",
        elem_type=onnx.TensorProto.FLOAT,
        shape=[None, None],
    )
    print(x)
    """
    name: "X"
    type {
      tensor_type {
        elem_type: 1
        shape {
          dim {
          }
          dim {
          }
        }
      }
    }
    """

    y = onnx.helper.make_tensor_value_info(
        name="Y",
        elem_type=onnx.TensorProto.INT32,
        shape=[1, 2],
    )
    print(y)
    """
    name: "Y"
    type {
      tensor_type {
        elem_type: 6
        shape {
          dim {
            dim_value: 1
          }
          dim {
            dim_value: 2
          }
        }
      }
    }

    """
    print(onnx.helper.printable_value_info(y))
    """
    %Y[INT32, 1x2]
    """


if __name__ == "__main__":
    main()
