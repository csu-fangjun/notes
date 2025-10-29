SenseVoice
==========

.. code-block:: bash

  qnn-onnx-converter \
    --input_network ./model.onnx \
    --output_path ./qnn_model_dynamic \
    --out_node logits \
    --input_dtype x float32 \
    --input_dtype prompt int32 \
    --input_dim x 1,300,560 \
    --input_dim prompt 4 \
    --float_bitwidth 16 \
    --use_per_channel_quantization

.. code-block:: bash

  2025-10-29 05:45:28,229 - 240 - WARNING - Symbolic shape inference Failed. Exception: Incomplete symbolic shape inference. Running normal shape inference.
  2025-10-29 05:45:44,439 - 240 - WARNING - Shape not found for tensor: /ctc_lo/MatMul_output_0
  WARNING: The argument `input_shapes` is deprecated. Please use 
  `overwrite_input_shapes` and/or `test_input_shapes` instead. An error will be 
  raised in the future.
  WARNING: the simplification stopped because of timeout. Please set environment variable `ONNXSIM_FIXED_POINT_ITERS` to a number higher than 50if you want further simplification.
  2025-10-29 05:56:30,769 - 235 - INFO - Simplified model validation is successful
  2025-10-29 05:58:56,511 - 235 - INFO - Skipping quantization, no input_list provided
  2025-10-29 05:58:56,511 - 235 - INFO - Saving QNN Model...
  2025-10-29 05:59:02,856 - 235 - INFO - Model CPP saved at: ./qnn_model_dynamic 
  2025-10-29 05:59:02,857 - 235 - INFO - Model BIN saved at: /content/qnn_model_dynamic.bin 
  2025-10-29 05:59:02,978 - 235 - INFO - Conversion complete!

.. code-block::

   file qnn_model_dynamic

   qnn_model_dynamic: C source, ASCII text, with very long lines (2378)

   file qnn_model_dynamic.bin

   qnn_model_dynamic.bin: POSIX tar archive

.. code-block::

  ls -lh qnn_model_dynamic*

.. code-block::

  -rw-r--r-- 1 root root 9.2M Oct 29 05:59 qnn_model_dynamic
  -rw-r--r-- 1 root root 444M Oct 29 05:59 qnn_model_dynamic.bin
  -rw-r--r-- 1 root root 4.4M Oct 29 05:59 qnn_model_dynamic_net.json

.. code-block::

   mv qnn_model_dynamic qnn_model_dynamic.cpp

.. code-block::

  export QNN_TARGET_ARCH="x86_64-linux-clang"

  python3 "${QNN_SDK_ROOT}/bin/x86_64-linux-clang/qnn-model-lib-generator" \
      -c "qnn_model_dynamic.cpp" \
      -b "qnn_model_dynamic.bin" \
      -o model_libs \
      -t ${QNN_TARGET_ARCH}

.. code-block::

   ls -lh model_libs/x86_64-linux-clang/

   -rwxr-xr-x 1 root root 448M Oct 29 06:18 libqnn_model_dynamic.so
