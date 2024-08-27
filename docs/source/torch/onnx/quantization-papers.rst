Quantization
============

TO READ
-------

  - 2017-Mixed precision training, See :cite:p:`micikevicius2017mixed`.
  - Achieving FP32 Accuracy for INT8 Inference Using Quantization Aware Training with NVIDIA TensorRT

    A blog, `<https://developer.nvidia.com/blog/achieving-fp32-accuracy-for-int8-inference-using-quantization-aware-training-with-tensorrt/>`_

  - 2019-Neural network distiller: A python package for dnn compression research

    See :cite:p`zmora2019neural`. It is from Intel.

    It also has a github repo at `<https://github.com/IntelLabs/distiller>`_

    Read its code about quantization! It has 4.3k stars!

  - 2011-Improving the speed of neural networks on CPUs

    See :cite:p:`vanhoucke2011improving`. It is from Google.

    Has stuff about SSE.

2020-Integer quantization for deep learning inference: Principles and empirical evaluation
------------------------------------------------------------------------------------------

See :cite:p:`wu2020integer`.

This paper is from NVidia. It lists a table comparing throughput of fp16, int8, int4, int1
on NVIDIA Turing GPUs.


An example:

.. literalinclude:: ./code/quantization-paper-test.py

2022-A survey of quantization methods for efficient neural network inference
----------------------------------------------------------------------------

See :cite:p:`gholami2022survey`

1998-Quantization
-----------------

See :cite:p:`gray1998quantization`.

.. rubric:: Quantization

.. bibliography:: ./quantization.bib
