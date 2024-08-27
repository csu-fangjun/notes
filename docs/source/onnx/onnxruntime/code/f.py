#!/usr/bin/env python3

from torch._custom_op import impl as custom_op
import torch
import onnx
import onnxscript
from onnxscript import opset18

import warnings
warnings.filterwarnings("ignore")

@custom_op.custom_op("mylibrary::my_add_op2")
def my_add_op2(x: torch.Tensor, y: torch.Tensor) -> torch.Tensor:
    # Since we are using mylibrary::my_add_op2, so the function
    # name must be my_add_op2; otherwise, it will throw an error
    # when this script is run
    pass

@my_add_op2.impl_abstract()
def my_add_op_impl_abstract_any_name_is_ok(x, y):
    return torch.empty_like(x)

@my_add_op2.impl("cpu")
def my_add_op_impl_any_name_is_ok(x, y):
    x = torch.nn.functional.relu(x)
    return x+y   # add x to itself, and round the result

class CustomFoo(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.register_parameter('foo', torch.nn.Parameter(torch.tensor([1.5, 2.5, 3.5, 4.5])))
        self.relu = torch.nn.ReLU()
    def forward(self, x):
        x = self.relu(x)
        return my_add_op2(x, self.foo)


custom_opset = onnxscript.values.Opset(domain="com.k2fsa.org", version=1)

@onnxscript.script(custom_opset)
def custom_my_add(x, y):
    return custom_opset.CustomOpOne2(x, y)

@torch.no_grad()
def main():
    torch._dynamo.allow_in_graph(my_add_op2)
    x = torch.randn(4)
    custom_addandround_model = CustomFoo()
    onnx_registry = torch.onnx.OnnxRegistry()
    onnx_registry.register_op(
        namespace="mylibrary", op_name="my_add_op2", overload="default", function=custom_my_add
        )

    export_options = torch.onnx.ExportOptions(onnx_registry=onnx_registry)
    onnx_program = torch.onnx.dynamo_export(
        custom_addandround_model, x,  export_options=export_options
        )
    onnx_program.save("./f.onnx")
    with open('f.txt', 'w') as f:
        f.write(str(onnx_program.model_proto))
    onnx_model = onnx.load("f.onnx")
    onnx.checker.check_model(onnx_model)


if __name__ == '__main__':
    main()
