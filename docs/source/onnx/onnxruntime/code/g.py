#!/usr/bin/env python3

from torch._custom_op import impl as custom_op
import torch
import onnx
import onnxscript
from onnxscript import opset18

import warnings
warnings.filterwarnings("ignore")

@custom_op.custom_op("mylibrary::my_cast")
def my_cast(x: torch.Tensor, scale: float = 0.25) -> torch.Tensor:
    # Since we are using mylibrary::my_cast, so the function
    # name must be my_cast; otherwise, it will throw an error
    # when this script is run
    return x.to(torch.float32)

@my_cast.impl_abstract()
def my_cast_impl_abstract_any_name_is_ok(x, scale: float = 0.25):
    return x.to(torch.float32)

@my_cast.impl("cpu")
def my_cast_impl_any_name_is_ok(x, scale: float = 0.25):
    return x.to(torch.float32)   # add x to itself, and round the result

class CustomFoo(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.register_buffer('foo', torch.tensor([10, 20], dtype=torch.uint8))
        self.scale = 0.125

    def forward(self, x):
        return x + my_cast(self.foo, self.scale)


custom_opset = onnxscript.values.Opset(domain="com.k2fsa.org", version=1)

@onnxscript.script(custom_opset, default_opset=opset18)
def custom_my_cast(x, scale: float = 0.5):
    return custom_opset.MyCast(x, scale)

@torch.no_grad()
def main():
    torch._dynamo.allow_in_graph(my_cast)
    x = torch.randn(2)
    custom_addandround_model = CustomFoo()
    onnx_registry = torch.onnx.OnnxRegistry()
    onnx_registry.register_op(
        namespace="mylibrary", op_name="my_cast", overload="default", function=custom_my_cast
        )

    export_options = torch.onnx.ExportOptions(onnx_registry=onnx_registry)
    onnx_program = torch.onnx.dynamo_export(
        custom_addandround_model, x,  export_options=export_options
        )
    onnx_program.save("./g.onnx")
    with open('g.txt', 'w') as f:
        f.write(str(onnx_program.model_proto))
    onnx_model = onnx.load("g.onnx")
    onnx.checker.check_model(onnx_model)


if __name__ == '__main__':
    main()
