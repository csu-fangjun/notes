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

To view the versions of rknn driver, 

  dmesg | grep -i rknpu

It prints::

  [    6.784814] RKNPU fdab0000.npu: Adding to iommu group 0
  [    6.784923] RKNPU fdab0000.npu: RKNPU: rknpu iommu is enabled, using iommu mode
  [    6.786126] RKNPU fdab0000.npu: can't request region for resource [mem 0xfdab0000-0xfdabffff]
  [    6.786146] RKNPU fdab0000.npu: can't request region for resource [mem 0xfdac0000-0xfdacffff]
  [    6.786156] RKNPU fdab0000.npu: can't request region for resource [mem 0xfdad0000-0xfdadffff]
  [    6.786580] [drm] Initialized rknpu 0.9.6 20240322 for fdab0000.npu on minor 1
  [    6.791864] RKNPU fdab0000.npu: RKNPU: bin=0
  [    6.792047] RKNPU fdab0000.npu: leakage=6
  [    6.792083] debugfs: Directory 'fdab0000.npu-rknpu' with parent 'vdd_npu_s0' already present!
  [    6.805376] RKNPU fdab0000.npu: pvtm=874
  [    6.809605] RKNPU fdab0000.npu: pvtm-volt-sel=3
  [    6.809648] debugfs: Directory 'fdab0000.npu-rknpu' with parent 'vdd_npu_s0' already present!
  [    6.811600] RKNPU fdab0000.npu: avs=0
  [    6.811748] RKNPU fdab0000.npu: l=10000 h=85000 hyst=5000 l_limit=0 h_limit=800000000 h_table=0

``rknpu 0.9.6 20240322`` contains the driver version.

``cat /sys/module/rknpu/version`` can also show the driver version, which is ``0.9.6``.

To show the version of the ``/usr/lib/librknnrt.so``, use::

  strings /usr/lib/librknnrt.so | grep "librknnrt

It prints::

  librknnrt.so
  librknnrt version: 1.4.0 (a10f100eb@2022-09-09T09:07:14)

To show the version of ``rknn_server``, run::

  rknn_server

It shows::

  start rknn server, version:1.3.0 (121b661 build: 2022-04-29 11:12:02)
  I NPUTransfer: Starting NPU Transfer Server, Transfer version 2.1.0 (b5861e7@2020-11-23T11:50:51)

We need to support RK3568、RK3566、RK3562、 RK3588、RV1106, and RV1103.
