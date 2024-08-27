protobuf notes
==============

repeated
--------

See

  - `<https://protobuf.dev/reference/python/python-generated/#repeated-fields>`


Two examples below:

  - 1. the repeated field contains messages
  - 2. the repeated field contain primitive fields


.. code-block:: protobuf

  message NodeProto {
    repeated string input = 1;    // namespace Value
  }

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

Usage in Python:


.. literalinclude:: ./code/protobuf/repeated.py
