Basics
======

.. code-block:: python3

   from rknn.api.rknn import RKNN

``RKNN.config`` has a parameter ``custom_string``.

.. code-block:: bash

   https://github.com/rockchip-linux/rknn-toolkit2/raw/refs/heads/master/rknn-toolkit2/packages/rknn_toolkit2-1.6.0+81f21f4d-cp311-cp311-linux_x86_64.whl

See `<https://github.com/rockchip-linux/rknpu2/blob/master/runtime/RK3588/Linux/librknn_api/include/rknn_api.h#L470>`_

.. code-block::

   int rknn_query(rknn_context context, rknn_query_cmd cmd, void* info, uint32_t size);


`<https://github.com/rockchip-linux/rknpu2/blob/master/runtime/RK3588/Linux/librknn_api/include/rknn_api.h#L117>`_

.. code-block::

       RKNN_QUERY_CUSTOM_STRING = 7,                           /* query the custom string */

`<https://github.com/rockchip-linux/rknpu2/blob/master/runtime/RK3588/Linux/librknn_api/include/rknn_api.h#L326>`_

.. code-block::

  typedef struct _rknn_custom_string {
      char string[1024];                                  /* the string of custom, lengths max to 1024 bytes */
  } rknn_custom_string;

So the max length of the custom string is 1023.

Examples:

  - Python on PC: `<https://github.com/rockchip-linux/rknn-toolkit2/blob/master/rknn-toolkit2/examples/onnx/resnet50v2/test.py#L87>`_
  - Python on the board: `<https://github.com/rockchip-linux/rknn-toolkit2/blob/master/rknn_toolkit_lite2/examples/resnet18/test.py>`_

To fix the following error::

  I RKNN: [14:24:11.881] RKNN Runtime Information: librknnrt version: 1.4.0 (a10f100eb@2022-09-09T09:07:14)
  I RKNN: [14:24:11.881] RKNN Driver Information: version: 0.9.6
  E RKNN: [14:24:11.881] 6, 1
  E RKNN: [14:24:11.881] Invalid RKNN model version 6
  E RKNN: [14:24:11.881] rknn_init, load model failed!
  E Catch exception when init runtime!
  E Traceback (most recent call last):
    File "/home/orangepi/packages/rknnlite/api/rknn_lite.py", line 148, in init_runtime
      self.rknn_runtime.build_graph(self.rknn_data, self.load_model_in_npu)
    File "rknnlite/api/rknn_runtime.py", line 919, in rknnlite.api.rknn_runtime.RKNNRuntime.build_graph
  Exception: RKNN init failed. error code: RKNN_ERR_FAIL

  Failed to init rknn runtime for ./decoder.rknn

See `<https://github.com/rockchip-linux/rknn-toolkit2/issues/316>`_
Download ``librknnrt.so`` from `<https://huggingface.co/csukuangfj/rknn-toolkit2/tree/main/rknn-toolkit2-v2.1.0-2024-08-08/rknpu2/runtime/Linux/librknn_api/aarch64>`_

Use::

  watch -n 1 cat /sys/kernel/debug/rknpu/load

to view the usage of npu cores.
