#!/usr/bin/env python3

import torch
import torch.nn as nn
import onnx
import onnxruntime as ort
import numpy as np
import os


class Foo(nn.Module):
    def forward(self, x):
        return x + 1


class Bar(nn.Module):
    def forward(self, x):
        return x - 1


def export_to_onnx():
    x = torch.rand(2, 3, dtype=torch.float32)
    f = Foo()
    torch.onnx.export(
        f,
        x,
        "f.onnx",
        verbose=False,
        input_names=["x1"],
        output_names=["y1"],
        dynamic_axes={
            "x1": {0: "N", 1: "T"},
            "y1": {0: "N", 1: "T"},
        },
    )

    x = torch.rand(1, dtype=torch.float32)
    b = Bar()
    torch.onnx.export(
        b,
        x,
        "b.onnx",
        verbose=False,
        input_names=["x2"],
        output_names=["y2"],
        dynamic_axes={
            "x2": {0: "N"},
            "y2": {0: "N"},
        },
    )


def merge_models():
    f = onnx.load("f.onnx")
    f = onnx.compose.add_prefix(f, prefix="f/")
    b = onnx.load("b.onnx")
    combined_model = onnx.compose.merge_models(f, b, io_map={})
    onnx.save(combined_model, "all.onnx")


def test_merged_model():
    # https://github.com/microsoft/onnxruntime/issues/10113
    options = ort.SessionOptions()
    options.inter_op_num_threads = 1
    options.intra_op_num_threads = 1

    all_model = onnx.load("all.onnx")

    extractor = onnx.utils.Extractor(all_model)

    f = extractor.extract_model(input_names=["f/x1"], output_names=["f/y1"])
    f_session = ort.InferenceSession(f.SerializeToString(), sess_options=options)
    f_inputs = f_session.get_inputs()
    f_out = f_session.run(["f/y1"], {"f/x1": np.array([[1, 3]], dtype=np.float32)})
    print(f_out[0])  # [[2. 4.]]

    b = extractor.extract_model(input_names=["x2"], output_names=["y2"])
    b_session = ort.InferenceSession(b.SerializeToString(), sess_options=options)
    b_inputs = b_session.get_inputs()
    b_out = b_session.run(["y2"], {"x2": np.array([1, 3], dtype=np.float32)})
    print(b_out[0])  # [0. 2.]


def main():
    export_to_onnx()
    merge_models()
    test_merged_model()
    os.remove("f.onnx")
    os.remove("b.onnx")
    os.remove("all.onnx")


if __name__ == "__main__":
    main()
