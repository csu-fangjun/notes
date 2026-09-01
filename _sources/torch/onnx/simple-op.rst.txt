Simple OPs
==========

.. literalinclude:: ./code/simple-op/model.py


linear
------

``nn.Linear`` has two parameters ``weight`` and ``bias``.

In PyTorch, ``weight.shape`` is ``(out_channels, in_channels)``.
But after exporting to onnx, ``model.onnx`` uses a shape ``(in_channels, out_channels)``,
which is a transpose of the PyTorch's weight.

To use int8 symmetric quantization for::

  tensor([[ 0.0928, -0.0400,  0.0666],
          [-0.5535, -0.2698,  0.4867],
          [ 0.5245, -0.3856,  0.3486],
          [ 0.4714,  0.2035, -0.4349]], requires_grad=True)

  w = model.my_linear.weight
  max_w = w.abs().max().item()
  scale = max_w * 2 / 255
  print(scale)
  print((w / scale).to(torch.int8))

It prints::

  0.0043414938683603325
  tensor([[  21,   -9,   15],
          [-127,  -62,  112],
          [ 120,  -88,   80],
          [ 108,   46, -100]], dtype=torch.int8)

Note that for symmetric quantization, zero point is 0.

In ``model.onnx``, the int8 weights are saved as::

  [
      [
          21,
          -127,
          120,
          108
      ],
      [
          -9,
          -62,
          -88,
          47
      ],
      [
          15,
          112,
          80,
          -100
      ]
  ]

Before quantization, the float32 weights in ``model.onnx`` are::

  [
      [
          0.09278726577758789,
          -0.5535404682159424,
          0.5244883298873901,
          0.4713994264602661
      ],
      [
          -0.04004639387130737,
          -0.26981082558631897,
          -0.3855680227279663,
          0.2035449743270874
      ],
      [
          0.06659042835235596,
          0.48669636249542236,
          0.34855782985687256,
          -0.43489107489585876
      ]
  ]

The file ``model.onnx.txt`` is given below:

.. literalinclude:: ./code/simple-op/model.onnx.txt

The file ``model.int8.onnx.txt`` is given below:

.. literalinclude:: ./code/simple-op/model.int8.onnx.txt

Note that onnxruntime uses::

  val_fp32 = scale * (val_quantized - zero_point)

The CPU implementation for DynamicLinearQuantizer can be found at

  - ``DynamicQuantizeLinear<T>::Compute``: `<https://github.com/microsoft/onnxruntime/blob/main/onnxruntime/core/providers/cpu/quantization/dynamicquantizelinear.cc#L23>`_

  - ``GetQuantizationParameter``: `<https://github.com/microsoft/onnxruntime/blob/main/onnxruntime/core/util/qmath.h>`_

    It shows how to compute the scale and zero_point. Note that it uses asymmetric quantization by default.

      - ``scale = (float_max - float_min) / (int_max - int min)``
      - ``zero_point = RoundHalfToEven(int_min - float_min / scale)``
  - ``MlasQuantizeLinearKernel``: `<https://github.com/microsoft/onnxruntime/blob/main/onnxruntime/core/mlas/lib/power/QuantizePower.cpp>`_

    It does the actual quantization using ``MLAS``.

