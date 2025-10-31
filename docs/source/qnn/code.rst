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
