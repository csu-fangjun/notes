Python notes
============

See `<https://onnx.ai/onnx/api/index.html#l-python-onnx-api>`_

.. code-block:: bash

   pip install onnx

The data structure is defined in a protocol buffer file

  `<https://github.com/onnx/onnx/blob/main/onnx/onnx.proto>`_

See `<https://protobuf.dev/reference/python/python-generated/>`_
for Python APIs for protocol buffers.

TensorProto
-----------

It is defined in `<https://github.com/onnx/onnx/blob/main/onnx/onnx.proto#L483>`_

`<https://github.com/onnx/onnx/blob/main/onnx/mapping.py>`_
defines a mapping to map datatypes from onnx to numpy.

.. literalinclude:: ./code/tensor-proto.py
   :language: python
   :linenos:
   :caption: ./code/tensor-proto.py

TensorShapeProto
----------------

It is defined in
`<https://github.com/onnx/onnx/blob/main/onnx/onnx.proto#L661>`_.

.. literalinclude:: ./code/tensor-shape-proto.py
   :language: python
   :linenos:
   :caption: ./code/tensor-shape-proto.py

One thing to note is that it contains a ``oneof`` field.
Also note it can contain symbolic names for shapes.

.. code-block:: proto

    message TensorShapeProto {
      message Dimension {
        oneof value {
          int64 dim_value = 1;
          string dim_param = 2;   // namespace Shape
        };
        // Standard denotation can optionally be used to denote tensor
        // dimensions with standard semantic descriptions to ensure
        // that operations are applied to the correct axis of a tensor.
        // Refer to https://github.com/onnx/onnx/blob/main/docs/DimensionDenotation.md#denotation-definition
        // for pre-defined dimension denotations.
        optional string denotation = 3;
      };
      repeated Dimension dim = 1;
    }

ValueInfoProto
==============
