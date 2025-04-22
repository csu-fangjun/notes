compile
=======

On my mac:

.. code-block:: python3

  >>> torch.__version__
  '2.2.2'
  >>> torch.compiler.list_backends()
  ['cudagraphs', 'inductor', 'onnxrt', 'openxla', 'openxla_eval', 'tvm']

On Linux:

.. code-block:: python3

  >>> torch.__version__
  '2.6.0+cu118'
  >>> torch.compiler.list_backends()
  ['cudagraphs', 'inductor', 'onnxrt', 'openxla', 'tvm']

TODO
----

- `<https://pytorch.org/docs/stable/torch.compiler_dynamic_shapes.html>`_
- `<https://pytorch.org/docs/stable/torch.compiler_dynamo_deepdive.html>`_
