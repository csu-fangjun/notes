#!/usr/bin/env python3

import numpy as np
import MNN
import torch


def main():
    interpreter = MNN.Interpreter("ex1.mnn")

    config = {}
    #  config["precision"] = "high"  # low, high, normal
    config["backend"] = "CPU"
    #  config["thread"] = 1
    session = interpreter.createSession(config)

    #  a = torch.tensor([1, -2.5, 3.2], dtype=torch.float32)
    #  b = a.numpy()

    input_tensor = interpreter.getSessionInput(session)
    interpreter.resizeTensor(input_tensor, (3,))
    interpreter.resizeSession(session)
    print("input_tensor.getShape()", input_tensor.getShape())

    input_data = MNN.expr.const(
        np.array([1, -2.5, 3.2], dtype=np.float32),
        (3,),
        MNN.expr.NCHW,
        MNN.expr.float,
    )
    input_tensor.copyFrom(MNN.Tensor(input_data))
    print("input_tensor.getNumpyData()", input_tensor.getNumpyData())

    interpreter.runSession(session)

    output_tensor = interpreter.getSessionOutput(session)
    print("output_tensor.getNumpyData()", output_tensor.getNumpyData())

    output_data = MNN.Tensor(
        output_tensor.getShape(), MNN.Halide_Type_Float, MNN.Tensor_DimensionType_Caffe
    )
    output_tensor.copyToHostTensor(output_data)
    print("output_data.getNumpyData()", output_data.getNumpyData())


if __name__ == "__main__":
    main()
