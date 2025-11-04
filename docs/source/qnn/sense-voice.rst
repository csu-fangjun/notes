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

  qnn-onnx-converter \
    --input_network ./model.onnx \
    --output_path ./qnn_model_dynamic \
    --out_node logits \
    --input_dtype x float32 \
    --input_dtype prompt int32 \
    --input_layout x NTF \
    --define_symbol N 1 \
    --define_symbol T 93 \
    --float_bitwidth 16 \
    --float_fallback \
    --use_per_row_quantization \
    --input_dim x 1,93,560 \
    --input_dim prompt 4

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

If we don't specify the ``-t``, it will show::

  2025-10-29 10:41:45,757 -    INFO - qnn-model-lib-generator: Target: x86_64-linux-clang	Library: /content/model_libs/x86_64-linux-clang/libqnn_model_dynamic.so
  2025-10-29 10:41:45,757 -    INFO - qnn-model-lib-generator: Target: aarch64-android	Library: /content/model_libs/aarch64-android/libqnn_model_dynamic.so

First working version
---------------------

.. code-block::

  wget https://hf-mirror.com/csukuangfj/qnn-toolkit/resolve/main/tmp/model-op17-static-93.onnx

  if [ ! -f input0-en.raw ]; then
  wget https://modelscope.cn/models/csukuangfj/2025-10-14/resolve/master/2025-10-29-qnn/input0-en.raw
  wget https://modelscope.cn/models/csukuangfj/2025-10-14/resolve/master/2025-10-29-qnn/input1-en.raw
  fi

  if [ ! -f input0.raw ]; then
  wget https://modelscope.cn/models/csukuangfj/2025-10-14/resolve/master/2025-10-29-qnn/input0.raw
  wget https://modelscope.cn/models/csukuangfj/2025-10-14/resolve/master/2025-10-29-qnn/input1.raw
  fi

  echo "/content/input0-en.raw /content/input1-en.raw" > input_list.txt

  echo "./input0-en.raw ./input1-en.raw" > input_list.txt

  #echo "/content/input0.raw /content/input1.raw" >> input_list.txt

  cat input_list.txt

  source py310/bin/activate

  pushd  qairt/2.33.0.250327/bin
  source envsetup.sh
  popd

  qnn-onnx-converter \
    --input_network ./model-op17-static-93.onnx \
    --output_path ./model-op17-static-93-quantized \
    --out_node logits \
    --input_list ./input_list.txt \
    --use_native_input_files  \
    --input_dtype x float32 \
    --input_dtype prompt int32 \
    --act_bitwidth 16 \
    --bias_bitwidth 32 \
    --input_layout x NTF

  mv model-op17-static-93-quantized model-op17-static-93-quantized.cpp

  python3 "${QNN_SDK_ROOT}/bin/x86_64-linux-clang/qnn-model-lib-generator" \
      -c "model-op17-static-93-quantized.cpp" \
      -b "model-op17-static-93-quantized.bin" \
      -o model_libs_quantized \
      -t aarch64-android

.. code-block::

  -rwxr-xr-x 1 root root 228M Nov  4 04:29 model_libs_quantized/aarch64-android/libmodel-op17-static-93-quantized.so

In ``model-op17-static-93-quantized_net.json``, we have::

    "x": {
            "id": 1,
            "type": 0,
            "dataFormat": 0,
            "data_type": 1046,
            "unquantized_data_type": 562,
            "permute_order_to_src": [
                    0,
                    1,
                    2
            ],
            "quant_params": {
                    "definition": 1,
                    "encoding": 0,
                    "is_overridden": false,
                    "scale_offset": {
                            "bitwidth": 16,
                            "minimum": -1.078358769416809,
                            "maximum": 24.36089515686035,
                            "scale": 0.00038817813037894666,
                            "offset": -2778,
                            "is_symmetric": false,
                            "is_fixed_point": true
                    }
            },
            "dims": [
                    1,
                    93,
                    560
            ],
            "is_dynamic_dims": [],
            "is_quantizable": true,
            "is_updateable": false
    }

    "prompt": {
            "id": 2,
            "type": 0,
            "dataFormat": 0,
            "data_type": 50,
            "unquantized_data_type": 50,
            "permute_order_to_src": [
                    0,
                    1
            ],
            "quant_params": {
                    "definition": 2147483647,
                    "encoding": 2147483647,
                    "is_overridden": false,
                    "scale_offset": {
                            "bitwidth": 0,
                            "minimum": 0.0,
                            "maximum": 0.0,
                            "scale": 0.0,
                            "offset": 0,
                            "is_symmetric": false,
                            "is_fixed_point": true
                    }
            },
            "dims": [
                    1,
                    4
            ],
            "is_dynamic_dims": [],
            "is_quantizable": false,
            "is_updateable": false
    },

  "logits": {
            "id": 4700,
            "type": 1,
            "dataFormat": 0,
            "data_type": 1046,
            "unquantized_data_type": 562,
            "permute_order_to_src": [
                    0,
                    1,
                    2
            ],
            "quant_params": {
                    "definition": 1,
                    "encoding": 0,
                    "is_overridden": false,
                    "scale_offset": {
                            "bitwidth": 16,
                            "minimum": -33.50352096557617,
                            "maximum": 38.97942352294922,
                            "scale": 0.0011060187825933099,
                            "offset": -30292,
                            "is_symmetric": false,
                            "is_fixed_point": true
                    }
            },
            "dims": [
                    1,
                    97,
                    25055
            ],
            "is_dynamic_dims": [],
            "is_quantizable": true,
            "is_updateable": false
    },

Output from my ``qnn-demo``:

.. code-block::

  input tensor 0, version 2
    id: 1
    name: x
    type: QNN_TENSOR_TYPE_APP_WRITE
    data format: 0
    data type: QNN_DATATYPE_UFIXED_POINT_16
    quantize info:
      encodingDefinition: 0x1
      quantizationEncoding: QNN_QUANTIZATION_ENCODING_SCALE_OFFSET
       scale: 0.000388178
       offset: -2778
    rank: 3
    dimensions: 1, 93, 560,
  input tensor 1, version 2
    id: 2
    name: prompt
    type: QNN_TENSOR_TYPE_APP_WRITE
    data format: 0
    data type: QNN_DATATYPE_INT_32
    quantize info:
      encodingDefinition: 0x7fffffff
      quantizationEncoding: QNN_QUANTIZATION_ENCODING_UNDEFINED
    rank: 2
    dimensions: 1, 4,
  output tensor 2940, version 2
    id: 4840
    name: logits
    type: QNN_TENSOR_TYPE_APP_READ
    data format: 0
    data type: QNN_DATATYPE_UFIXED_POINT_16
    quantize info:
      encodingDefinition: 0x1
      quantizationEncoding: QNN_QUANTIZATION_ENCODING_SCALE_OFFSET
       scale: 0.00110602
       offset: -30292
    rank: 3
    dimensions: 1, 97, 25055,

To generate test data for ``x``:

.. code-block::

    features = compute_feat(
        samples=samples,
        sample_rate=sample_rate,
    )
    print("features.shape", features.shape)
    if features.shape[0] > args.num_frames:
        features = features[: args.num_frames]
    elif features.shape[0] < args.num_frames:
        pad_width = ((0, args.num_frames - features.shape[0]), (0, 0))
        padding = np.zeros(())
        features = np.pad(features, pad_width, mode="constant", constant_values=0)

    scale = 0.000388178
    offset = -2778
    features = np.round(features / scale - offset).clip(0, 65535).astype(np.uint16)

    features.tofile("input0.raw")

To generate test data for ``prompt``:

.. code-block::

    language_auto = 0
    language_zh = 3
    language_en = 4
    language_yue = 7
    language_ya = 11
    language_ko = 12
    language_nospeech = 13

    language = language_auto

    with_itn = 14
    without_itn = 15

    text_norm = with_itn

    prompt = np.array([language, 1, 2, text_norm], dtype=np.int32)
    prompt.tofile("input1.raw")

Test with qnn-net-run::

  ./qnn-net-run --log_level verbose --model ./libmodel-op17-static-93-quantized.so --backend ./libQnnHtp.so --input_list ./input_list.txt  --output_dir ./out --use_native_input_files=true

.. code-block:: bash

  pandora:/data/local/tmp $ ls -l out/Result_0/logits.raw
  -rw-rw-rw- 1 shell shell 9721340 2025-11-04 12:52 out/Result_0/logits.raw
  pandora:/data/local/tmp $ bc
  >>> 9721340/25055/4
  97

.. code-block:: python

  import numpy as np

  def load_tokens(filename):
      ans = dict()
      i = 0
      with open(filename, encoding="utf-8") as f:
          for line in f:
              ans[i] = line.strip().split()[0]
              i += 1
      return ans


  logits = np.fromfile("./logits.raw", dtype=np.float32).reshape((-1, 25055))

  idx = logits.argmax(axis=-1)
  print("idx", idx)
  print(len(idx))
  prev = -1
  ids = []
  for i in idx:
      if i != prev:
          ids.append(i)
      prev = i
  ids = [i for i in ids if i != 0]
  print(ids)

  tokens = load_tokens("./tokens.txt")
  text = "".join([tokens[i] for i in ids])

  text = text.replace("_", " ")
  print(text)

