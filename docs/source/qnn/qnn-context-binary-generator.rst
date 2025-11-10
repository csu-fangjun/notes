qnn-context-binary-generator
============================

soc id and hexagon arch id
---------------------------

See

  - `<https://github.com/alibaba/MNN/wiki/npu>`_
  - `<https://github.com/tianxf99/executorch/blob/main/backends/qualcomm/serialization/qc_compiler_spec.fbs>`_
  - `<https://github.com/tianxf99/executorch/blob/main/backends/qualcomm/utils/utils.py#L963>`_

  - SA: Snapdragon Automotive
  - SM: Snapdragon Mobile

.. list-table::

 * - Hardware
   - SOC ID
   - Hexagon arch
 * - SA8295
   - 39
   - 68
 * - 888 (SM8350)
   - 28
   - 68
 * - 8 Gen 1 (SM8450)
   - 36
   - 69
 * - 8+ Gen 1 (SM8475)
   - 42
   - 69
 * - 8 Gen 2 (SM8550)
   - 43
   - 73
 * - 8 Gen 3 (SM8650)
   - 57
   - 75
 * - 7 Gen 2
   - 54
   - 75
 * - 8 Elite (SM8750)
   - 69
   - 79
 * - 8 Gen 5
   - 79
   - 80
 * - SSG2115P
   - 46
   - 73



config file
-----------

See `<https://github.com/alibaba/MNN/blob/6686bed19bf8a1cd61878a82e53d20c482fffdb3/tools/cpp/MNN2QNNModel.cpp#L350>`_

It generates two json files:

context_config.json
::::::::::::::::::::

.. code-block:: json

  {
    "backend_extensions": {
      "shared_library_path": "/content/qairt/2.33.0.250327/lib/x86_64-linux-clang/libQnnHtpNetRunExtensions.so",
      "config_file_path": "./htp_backend_extensions.json"
    }
  }

htp_backend_extensions.json
:::::::::::::::::::::::::::

.. code-block:: json

  {
    "graphs": [
      {
        "vtcm_mb": 8,
        "graph_names": ["model_op17_static_93_quantized"],
        "O": 3.0,
        "fp16_relaxed_precision": 1,
        "weights_packing": true,
        "hvx_threads": 4
      }
    ],
    "devices": [
      {
        "soc_id": 79,
        "dsp_arch": "v80",
        "cores": [
          {
            "core_id": 0,
            "perf_profile": "burst",
            "rpc_control_latency": 100
          }
        ]
      }
    ],
    "context": {
      "weight_sharing_enabled": true
    }
  }

Run command
-----------

.. code-block:: bash

  "${QNN_SDK_ROOT}/bin/x86_64-linux-clang/qnn-context-binary-generator" \
    --model=./libmodel.so \
    --backend=${QNN_SDK_ROOT}/lib/x86_64-linux-clang/libQnnHtp.so \
    --binary_file=./model.bin \
    --config_file=./context_config.json
