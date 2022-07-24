#!/usr/bin/env python3

import onnx


def main():
    model = onnx.load("f.onnx")
    #  print(model)
    # Check that the model is well formed
    onnx.checker.check_model(model)
    # Print a human readable representation of the graph
    print(onnx.helper.printable_graph(model.graph))
    onnx.save(model, "f2.onnx")


if __name__ == "__main__":
    main()
