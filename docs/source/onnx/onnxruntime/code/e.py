#!/usr/bin/env python3

from torch._custom_op import impl as custom_op
import torch
import onnx
import onnxscript
from onnxscript import opset18

import warnings
warnings.filterwarnings("ignore")

@custom_op.custom_op("mylibrary::my_add_op")
def my_add_op(x: torch.Tensor, y: torch.Tensor) -> torch.Tensor:
    # Since we are using mylibrary::my_add_op, so the function
    # name must be my_add_op; otherwise, it will throw an error
    # when this script is run
    pass

@my_add_op.impl_abstract()
def my_add_op_impl_abstract_any_name_is_ok(x, y):
    return torch.empty_like(x)

@my_add_op.impl("cpu")
def my_add_op_impl_any_name_is_ok(tensor_x):
    return torch.round(tensor_x + tensor_x)  # add x to itself, and round the result

class CustomFoo(torch.nn.Module):
    def forward(self, x, y):
        return my_add_op(x, y)


custom_opset = onnxscript.values.Opset(domain="com.k2fsa.org", version=1)

@onnxscript.script(custom_opset)
def custom_my_add(x, y):
    return custom_opset.CustomOpOne(x, y)

def main():
    torch._dynamo.allow_in_graph(my_add_op)
    x = torch.randn(3)
    y = torch.randn(3)
    custom_addandround_model = CustomFoo()
    onnx_registry = torch.onnx.OnnxRegistry()
    onnx_registry.register_op(
        namespace="mylibrary", op_name="my_add_op", overload="default", function=custom_my_add
        )

    export_options = torch.onnx.ExportOptions(onnx_registry=onnx_registry)
    onnx_program = torch.onnx.dynamo_export(
        custom_addandround_model, x, y, export_options=export_options
        )
    onnx_program.save("./e.onnx")
    with open('e.txt', 'w') as f:
        f.write(str(onnx_program.model_proto))
    onnx_model = onnx.load("e.onnx")
    onnx.checker.check_model(onnx_model)


if __name__ == '__main__':
    main()
