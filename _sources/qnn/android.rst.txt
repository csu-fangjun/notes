Android
=======



libcdsprpc.so
-------------

.. code-block:: bash

  <uses-native-library
              android:name="libcdsprpc.so"
              android:required="false"/>

``libcdsprpc.so`` is located in ``/vendor/lib64`` on my Xiaomi 17 Pro.

I have to put ``libQnnHtpV81Stub.so`` inside ``jniLibs/arm64-v8a`` together with using the above ``libcdsprpc.so``
in ``AndroidManifest.xml`` to avoid the 14001 error code from deviceCreate.

`<https://github.com/google-ai-edge/LiteRT/blob/01113f67fba44fb9547496500c804b400a90a571/litert/kotlin/src/main/AndroidManifest.xml#L47>`_
also uses this for QualComm NPU. It also has two lines for MTK NPU.

`<https://github.com/zhuqingquan/notes/blob/103d806170130164d1f918761d5c7f6f54ddb85b/%E6%B7%B1%E5%BA%A6%E5%AD%A6%E4%B9%A0-%E7%A5%9E%E7%BB%8F%E7%BD%91%E7%BB%9C-%E4%BA%BA%E5%B7%A5%E6%99%BA%E8%83%BD-AI/%E5%9F%BA%E7%A1%80%E7%9F%A5%E8%AF%86%E7%82%B9%E5%A4%87%E5%BF%98.md#%E9%83%A8%E7%BD%B2%E5%88%B0android%E6%89%8B%E6%9C%BA%E4%B8%AD%E8%BF%90%E8%A1%8C>`_ has some explanations about ``libcdsprpc.so``.



`<https://github.com/dengzii/rwkv_dart/>`_ has a dart example about it. See also
`<https://github.com/MollySophia/rwkv-mobile>`_

rwkv-mobile also has examples for coreml using c++!

Read `<https://github.com/MollySophia/rwkv-qualcomm>`_!

.. code-block::

  2025-11-20 09:33:13.728 27029-27029 sherpa-onnx             com...a.onnx.simulate.streaming.asr  W  ret for LD_LIBRARY_PATH: 0, :/data/user/0/com.k2fsa.sherpa.onnx.simulate.streaming.asr:/data/data/com.k2fsa.sherpa.onnx.simulate.streaming.asr/files:/vendor/dsp/cdsp:/vendor/lib64:/

  2025-11-20 09:33:13.728 27029-27029 sherpa-onnx             com...a.onnx.simulate.streaming.asr  W  ret for ADSP_LIBRARY_PATH: 0, ;/data/user/0/com.k2fsa.sherpa.onnx.simulate.streaming.asr/files;/vendor/dsp/cdsp;/vendor/lib/rfsa/adsp;/system/lib/rfsa/adsp;/vendor/dsp/dsp;/vendor/dsp/images;/dsp;/data/local/tmp/mv_dlc;/vendor/lib/rfsa/adsp;/vendor/dsp/cdsp;/system/lib/rfsa/adsp;/system/vendor/lib/rfsa/adsp;/dsp

  2025-11-20 09:33:13.742 27029-27029 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  I  vendor/qcom/proprietary/adsprpc/src/fastrpc_apps_user.c:7565: multidsplib_env_init: libcdsprpc.so loaded



  2025-11-20 09:33:13.781 27029-13805 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  E  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:377: Error 0x2: apps_std_fopen_fd failed for ./libQnnHtpV81Skel.so (No such file or directory)
  2025-11-20 09:33:13.781 27029-13805 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  E  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:377: Error 0x2: apps_std_fopen_fd failed for ./libQnnHtpV81Skel.so (No such file or directory)
  2025-11-20 09:33:13.781 27029-13805 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  E  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:377: Error 0x2: apps_std_fopen_fd failed for /data/user/0/com.k2fsa.sherpa.onnx.simulate.streaming.asr/files/cdsp/./libQnnHtpV81Skel.so (No such file or directory)
  2025-11-20 09:33:13.781 27029-13805 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  E  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:377: Error 0x2: apps_std_fopen_fd failed for /data/user/0/com.k2fsa.sherpa.onnx.simulate.streaming.asr/files/./libQnnHtpV81Skel.so (No such file or directory)
  2025-11-20 09:33:13.781 27029-13805 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  E  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:377: Error 0xd: apps_std_fopen_fd failed for /vendor/dsp/cdsp/cdsp/./libQnnHtpV81Skel.so (Permission denied)
  2025-11-20 09:33:13.781 27029-13805 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  E  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:377: Error 0xd: apps_std_fopen_fd failed for /vendor/dsp/cdsp/./libQnnHtpV81Skel.so (Permission denied)
  2025-11-20 09:33:13.781 27029-13805 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  E  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:377: Error 0x2: apps_std_fopen_fd failed for /vendor/lib/rfsa/adsp/cdsp/./libQnnHtpV81Skel.so (No such file or directory)

  2025-11-20 09:33:13.789 27029-13805 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  I  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:1236: Successfully opened file /vendor/lib/rfsa/adsp/./libQnnHtpV81Skel.so


.. code-block::

   file jniLibs/arm64-v8a/libQnnHtpV81Skel.so

   arm64-v8a/libQnnHtpV81Skel.so: ELF 32-bit LSB shared object, QUALCOMM DSP6, version 1 (SYSV), dynamically linked, stripped

Note that it is a .so file for 32-bit operating systems. If we put it in arm64-v8a, then we need to set

.. code-block::

   // kotlin
   val path = context.applicationInfo.nativeLibraryDir

   // c++
   setenv("ADSP_LIBRARY_PATH", path.c_str(), 1);

Otherwise, the code cannot locate where ``libQnnHtpV81Skel.so`` is and will show the following::

  2025-11-20 11:35:35.292 17652-26428 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  E  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:377: Error 0x2: apps_std_fopen_fd failed for /odm/lib/rfsa/adsp/cdsp/./libQnnHtpV81Skel.so (No such file or directory)
  2025-11-20 11:35:35.292 17652-26428 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  E  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:377: Error 0x2: apps_std_fopen_fd failed for /odm/lib/rfsa/adsp/./libQnnHtpV81Skel.so (No such file or directory)
  2025-11-20 11:35:35.292 17652-26428 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  E  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:377: Error 0x2: apps_std_fopen_fd failed for /vendor/lib/rfsa/adsp//cdsp/./libQnnHtpV81Skel.so (No such file or directory)
  2025-11-20 11:35:35.293 17652-26429 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  E  vendor/qcom/proprietary/adsprpc/src/log_config.c:223:Enabled adspmsgd with mask 8
  2025-11-20 11:35:35.293 17652-26429 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  W  vendor/qcom/proprietary/adsprpc/src/log_config.c:449:file_watcher_thread: Couldn't find file com.k2fsa.sherpa.onnx.simulate.streaming.asr.farf, errno (No such file or directory) at ;/vendor/lib64/rfs/dsp;/vendor/lib/rfsa/adsp;/vendor/lib/rfsa/dsp;/vendor/dsp;
  2025-11-20 11:35:35.300 17652-26428 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  D  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:369: apps_std_fopen_fd done for /vendor/lib/rfsa/adsp//./libQnnHtpV81Skel.so with fsize:8756920       fopen:7us, fstat:1us, read:7264us,       rpc_alloc:436us, mmap:496us fd 0xd9 error_code 0x0
  2025-11-20 11:35:35.300 17652-26428 com.k2fsa....eaming.asr com...a.onnx.simulate.streaming.asr  I  vendor/qcom/proprietary/adsprpc/src/apps_std_imp.c:1236: Successfully opened file /vendor/lib/rfsa/adsp//./libQnnHtpV81Skel.so

In the end, deviceCreate will fail with the error code ``1008``, which means ``QNN_COMMON_ERROR_INCOMPATIBLE_BINARIES``::

  because the required skeleton (skel) libraries are missing or can’t be loaded correctly.


To fix that, we need to set ``ADSP_LIBRARY_PATH``.

.. literalinclude:: ./code/android-qnn-log-1.txt
