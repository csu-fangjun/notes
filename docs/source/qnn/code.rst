code
====

- `<https://github.com/alibaba/MNN/blob/5047919a1ae594d090ee54c7ea3403a9dee8cad4/source/backend/qnn/backend/QNNWrapper.hpp#L12>`_

- `<https://github.com/UbiquitousLearning/mllm/blob/782926d5f2c0c9cc0c0df7d7dc5f968656df272b/mllm/backends/qnn/QNNBackend.hpp#L83>`_

  Line 81, it has::

    std::string getBackendBuildId(QNN_INTERFACE_VER_TYPE &qnnInterface) {
        char *backendBuildId{nullptr};
        if (QNN_SUCCESS != qnnInterface.backendGetBuildId((const char **)&backendBuildId)) {
            MLLM_LOG_ERROR_LEGACY("Unable to get build Id from the backend.");
        }
        return (backendBuildId == nullptr ? std::string("") : std::string(backendBuildId));
    }

- `<https://github.com/XiaoMi/StableDiffusionOnDevice/tree/65f09ae58a7c4a4c14aaeaaeaf5f5376a72f8b74/app/src/main/cpp/qnn_8550/include/QNN>`_

  - It contains header files.
  - ``CMakeLists.txt``: `<https://github.com/XiaoMi/StableDiffusionOnDevice/blob/65f09ae58a7c4a4c14aaeaaeaf5f5376a72f8b74/app/src/main/cpp/CMakeLists.txt>`_


- `<https://github.com/chraac/llama.cpp/blob/bc6d86af6353da1da2f07b4670c61fbaa60c8cfc/ggml/src/ggml-qnn/qnn/qnn-lib.cpp#L491>`_

  - Line 419, load system lib, call ``QnnSystemInterface_getProviders``
  - Line 481, load backend lib, call ``QnnInterface_getProviders``

- QnnModel_composeGraphs

  See 

    - `<https://github.com/asfahl/EML_2024/blob/5fc62b687865b46e890e0f5de303a9682142127d/Week_8/model/resnet18_int8.cpp>`_
    - `<https://github.com/quic/ai-engine-direct-helper/blob/aa658eb2f26436efd88ae62f51698c23d03a4935/src/Utils/DynamicLoadUtil.cpp#L102>`_


When using v2.32 with my Xiaomi 17, I get::

  backend build ID: v2.32.0.250228225014_116386
       0.0ms [INFO   ] QnnDsp <I> QnnLog_create started.
       0.0ms [VERBOSE] QnnDsp <V> Registered a new graph environment 1 with priority: 100, num hvx threads: 0, num hmx threads: 1001
       0.0ms [WARN   ] QnnDsp <W> Initializing HtpProvider
       0.0ms [VERBOSE] QnnDsp <V> Creating default router
       0.0ms [VERBOSE] QnnDsp <V> RouterFastRPC create
       0.0ms [VERBOSE] QnnDsp <V> HTP: Initializing the router
       0.0ms [INFO   ] QnnDsp <I> exit with 0
       0.0ms [INFO   ] QnnDsp <I> exit with 0
       0.0ms [ERROR  ] QnnDsp <E> Stub lib id mismatch: expected (v2.32.0.250228225014_116386), detected (v2.33.0.250327124043_117917)
       0.0ms [ERROR  ] QnnDsp <E> Unable to load Remote symbols 1008
       0.0ms [ERROR  ] QnnDsp <E> Unable to load Remote symbols 1008
       0.0ms [VERBOSE] QnnDsp <V> Async property not supported. Skipping setup async threads
       0.0ms [VERBOSE] QnnDsp <V> Detected Snapdragon SOC SM8850 with 1 SOCs
       0.0ms [VERBOSE] QnnDsp <V> Allocating PlatformInfo struct size 120
       0.0ms [VERBOSE] QnnDsp <V> HTP: Initializing the log registry

.. code-block:: bash

  pandora:/data/local/tmp $ strings /vendor/lib/rfsa/adsp/libQnnHtpV81Skel.so  | grep AISW_VERSION
  AISW_VERSION: 2.33.0

  pandora:/data/local/tmp $ strings /vendor/lib/rfsa/adsp/libQnnHtpV81Skel.so  | grep v2.33
  v2.33.0.250327124043_117917
  v2.33.0.250327124043_117917.d278150d6a
