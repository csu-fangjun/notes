#!/usr/bin/env python3
import onnx
import numpy as np


def test_dtype():
    # the following line is not portable as it uses the internal implementation detail
    #  assert onnx.mapping.TENSOR_TYPE_TO_NP_TYPE[onnx.TensorProto.FLOAT] == np.float32
    assert onnx.helper.tensor_dtype_to_np_dtype(onnx.TensorProto.FLOAT) == np.float32
    assert onnx.helper.tensor_dtype_to_np_dtype(onnx.TensorProto.INT8) == np.int8

    # We can convert a dtype to a string
    assert (
        onnx.helper.tensor_dtype_to_string(onnx.TensorProto.FLOAT)
        == "TensorProto.FLOAT"
    )
    assert onnx.TensorProto.DataType.Name(onnx.TensorProto.FLOAT) == "FLOAT"


def test_make_tensor():
    v = np.array([[1, 2], [3, 4]])
    t = onnx.helper.make_tensor(
        name="my",
        data_type=onnx.helper.np_dtype_to_tensor_dtype(v.dtype),
        dims=v.shape,
        vals=v,
    )
    print(t)

    """
    dims: 2
    dims: 2
    data_type: 7
    int64_data: 1
    int64_data: 2
    int64_data: 3
    int64_data: 4
    name: "my"
    """


def test_build_tensor_manually():
    n = np.arange(5, dtype=np.float32)
    t = onnx.TensorProto()
    t.name = "my-tensor"
    t.data_type = onnx.TensorProto.FLOAT
    t.dims.extend(n.shape)
    t.float_data.extend(n)
    print(t)
    """
    dims: 5
    data_type: 1
    float_data: 0.0
    float_data: 1.0
    float_data: 2.0
    float_data: 3.0
    float_data: 4.0
    name: "my-tensor"
    """


def main():
    test_dtype()
    test_make_tensor()
    test_build_tensor_manually()


if __name__ == "__main__":
    main()
