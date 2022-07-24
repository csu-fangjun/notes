#!/usr/bin/env python3

import onnxruntime as ort
import numpy as np


def main():
    # https://github.com/microsoft/onnxruntime/issues/10113
    options = ort.SessionOptions()
    options.inter_op_num_threads = 1
    options.intra_op_num_threads = 1

    ort_session = ort.InferenceSession("f.onnx", sess_options=options)

    x = np.arange(24).reshape(2, 3, 4).astype(np.float32)
    ortvalue = ort.OrtValue.ortvalue_from_numpy(x)
    assert ortvalue.device_name() == "cpu"
    assert list(ortvalue.shape()) == list(x.shape)
    assert ortvalue.data_type() == "tensor(float)"
    assert ortvalue.is_tensor() is True

    results = ort_session.run(["y"], {"x": ortvalue})
    print(results)

    ort_inputs = {ort_session.get_inputs()[0].name: x}
    results = ort_session.run(["y"], ort_inputs)
    print(results)

    results = ort_session.run(["y"], {"x": x})
    print(results)

    # https://onnxruntime.ai/docs/api/python/api_summary.html#onnxruntime.NodeArg
    inputs = ort_session.get_inputs()
    assert isinstance(inputs, list)
    assert len(inputs) == 1
    assert isinstance(inputs[0], ort.NodeArg)
    print(inputs[0].name, inputs[0].type, inputs[0].shape)
    assert inputs[0].name == "x"
    assert inputs[0].type == "tensor(float)"
    assert inputs[0].shape == ["batch_size", "T", 4]

    outputs = ort_session.get_outputs()
    assert isinstance(outputs, list)
    assert isinstance(outputs[0], ort.NodeArg)
    assert len(outputs) == 1
    assert outputs[0].name == "y"
    assert outputs[0].type == "tensor(float)"
    assert outputs[0].shape == ["y_dynamic_axes_1", "y_dynamic_axes_2", 4]


if __name__ == "__main__":
    main()
