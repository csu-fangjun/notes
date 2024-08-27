#!/usr/bin/env python3

from onnxscript import opset15 as op
from onnxscript import script, FLOAT
import onnx
import torch
import onnxruntime as ort

class Model:
    def __init__(self, filename):
        session_opts = ort.SessionOptions()
        self.session_opts = session_opts
        self.model = ort.InferenceSession(
            filename,
            sess_options=self.session_opts,
            providers=["CPUExecutionProvider"],
        )

    def run(
        self,
        x: torch.Tensor,
    ) -> torch.Tensor:
        y = self.model.run(
            [
                self.model.get_outputs()[0].name,
            ],
            {
                self.model.get_inputs()[0].name: x.numpy(),
            },
        )[0]
        return torch.from_numpy(y)

@script()
def Softplus(x: FLOAT):
    return op.Log(op.Exp(x) + 1.0)

def main():
    #  fp = Softplus.to_function_proto()
    #  print(fp)
    mp = Softplus.to_model_proto()
    print('type(mp)', type(mp)) # <class 'onnx.onnx_ml_pb2.ModelProto'>
    mp.producer_name = 'next-gen kaldi'
    mp.producer_version = '1.10.22'
    mp.model_version = 99
    mp.doc_string = 'my first example model with onnxscript'

    # add meta data
    p = mp.metadata_props.add()
    p.key = 'my-numbers'
    p.value = '1,2,3'


    onnx.save_model(mp, 'a.onnx')
    print(mp)

    x = torch.tensor([1, 0.5])
    m = Model('a.onnx')
    y = m.run(x)
    print(x, y)

    y2 = Softplus(x.numpy())
    print(y2)

if __name__ == '__main__':
    main()
