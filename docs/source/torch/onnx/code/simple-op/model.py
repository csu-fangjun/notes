#!/usr/bin/env python3

from typing import Any, Dict

import torch
import torch.nn as nn
from onnxruntime.quantization import QuantType, quantize_dynamic

import onnx


def add_meta_data(filename: str, meta_data: Dict[str, Any]):
    """Add meta data to an ONNX model. It is changed in-place.

    Args:
      filename:
        Filename of the ONNX model to be changed.
      meta_data:
        Key-value pairs.
    """
    model = onnx.load(filename)
    print(model)

    while len(model.metadata_props):
        model.metadata_props.pop()

    for key, value in meta_data.items():
        meta = model.metadata_props.add()
        meta.key = key
        meta.value = str(value)

    onnx.save(model, filename)


class Model(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.my_linear = nn.Linear(3, 4)
        self.my_relu = torch.nn.ReLU()

    def forward(self, x):
        y = self.my_linear(x)
        y = self.my_relu(y)
        return y


def main():
    model = Model()
    print(list(model.named_parameters()))
    x = torch.rand(2, 5, 3)
    torch.onnx.export(
        model,
        x,
        "model.onnx",
        input_names=["x"],
        output_names=["y"],
        dynamic_axes={
            "x": {0: "N"},
            "y": {0: "N"},
        },
    )
    print(list(model.parameters()))
    meta_data = {
        "date": 20240822,
        "author": "me",
        "version": 10,
    }
    add_meta_data("model.onnx", meta_data)

    quantize_dynamic(
        model_input="model.onnx",
        model_output="model.int8.onnx",
        op_types_to_quantize=["MatMul", "Add"],
        weight_type=QuantType.QInt8,
    )
    w = model.my_linear.weight
    max_w = w.abs().max().item()
    scale = max_w * 2 / (255 - 1)
    print(scale)
    print((w / scale).to(torch.int8))

    print("----")

    m = onnx.load("model.onnx")
    with open("model.onnx.txt", "w") as f:
        f.write(str(m))

    m_int8 = onnx.load("model.int8.onnx")
    with open("model.int8.onnx.txt", "w") as f:
        f.write(str(m_int8))


if __name__ == "__main__":
    torch.manual_seed(20240820)
    main()
