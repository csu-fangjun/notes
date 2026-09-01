aimet
=====

Doc: `<https://quic.github.io/aimet-pages/releases/latest/overview/install/quick-start.html>`_

  - Requires: Ubuntu 22.04, Python 3.10, x64

.. code-block:: bash

  pip install torch==2.2.0+cpu -f https://download.pytorch.org/whl/torch "numpy<2" aimet-onnx

Otherwise, it installs torch with CUDA support.

.. code-block::

  (py310) fangjun:qnn$ python3
  Python 3.10.12 (main, Aug 15 2025, 14:32:43) [GCC 11.4.0] on linux
  Type "help", "copyright", "credits" or "license" for more information.
  >>> import aimet_onnx
  >>> print(aimet_onnx.__version__)
  2.18.0
  >>>
