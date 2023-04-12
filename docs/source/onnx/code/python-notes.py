#!/usr/bin/env python3
import onnx


def show_version():
    print("onnx.__version__", onnx.__version__)
    print("onnx.IR_VERSION", onnx.IR_VERSION)
    print("onnx.defs.onnx_opset_version", onnx.defs.onnx_opset_version())
    """
    onnx.__version__ 1.12.0
    onnx.IR_VERSION 8
    onnx.defs.onnx_opset_version 17
    """


def test_tensor_proto_data_type():
    pass


def test_tensor_proto():
    tensor_proto = onnx.TensorProto()
    tensor_proto.dims.append(1)
    assert tensor_proto.dims == [1]


def linear_regression():
    pass


def main():
    show_version()
    test_tensor_proto()
    linear_regression()


if __name__ == "__main__":
    main()
