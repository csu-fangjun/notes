Simple OPs
==========

.. literalinclude:: ./code/simple-op/model.py


linear
------

``nn.Linear`` has two parameters ``weight`` and ``biase``.

In PyTorch, ``weight.shape`` is ``(out_channels, in_channels)``.
But after exporting to onnx, ``model.onnx`` use a shape ``(in_channels, out_channels)``, 
which is a transpose of the PyTorch's weight.

To use int8 quantization for::

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

In ``model.onnx``, the int8 weights is saved as::

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

Before quantization, the float32 weight in ``model.onnx`` is::

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
