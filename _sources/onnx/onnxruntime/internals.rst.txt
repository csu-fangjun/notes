Internals
=========

OrtApiBase
----------

It is a struct containing two function pointers.

.. code-block:: c++

  // https://github.com/microsoft/onnxruntime/blob/main/include/onnxruntime/core/session/onnxruntime_c_api.h
  struct OrtApiBase {
    const OrtApi*(ORT_API_CALL* GetApi)(uint32_t version)NO_EXCEPTION;
    const char*(ORT_API_CALL* GetVersionString)(void)NO_EXCEPTION;
  };

In `<https://github.com/microsoft/onnxruntime/blob/main/onnxruntime/core/session/onnxruntime_c_api.cc>`_, it uses a lot of
static assertions

.. code-block:: c++

  // https://github.com/microsoft/onnxruntime/blob/main/onnxruntime/core/session/onnxruntime_c_api.cc

  // OrtApiBase can never change as there is no way to know what version of OrtApiBase is returned by OrtGetApiBase.
  static_assert(sizeof(OrtApiBase) == sizeof(void*) * 2, "New methods can't be added to OrtApiBase as it is not versioned");
  static_assert(offsetof(OrtApiBase, GetApi) / sizeof(void*) == 0, "These functions cannot be reordered");
  static_assert(offsetof(OrtApiBase, GetVersionString) / sizeof(void*) == 1, "These functions cannot be reordered");
  static_assert(std::is_same_v<decltype(OrtApiBase::GetApi), const OrtApi*(ORT_API_CALL*)(uint32_t)NO_EXCEPTION>, "This function's signature can never change");
  static_assert(std::is_same_v<decltype(OrtApiBase::GetVersionString), const char*(ORT_API_CALL*)(void)NO_EXCEPTION>, "This function's signature can never change");

It defines a global variable in `<https://github.com/microsoft/onnxruntime/blob/main/onnxruntime/core/session/onnxruntime_c_api.cc>`_

.. code-block:: c++

  static constexpr OrtApiBase ort_api_base = {
      &OrtApis::GetApi,
      &OrtApis::GetVersionString};

  const OrtApiBase* ORT_API_CALL OrtGetApiBase(void) NO_EXCEPTION {
    return &ort_api_base;
  }

  ORT_API(const OrtApi*, OrtApis::GetApi, uint32_t version) {
    if (version >= 1 && version <= ORT_API_VERSION)
      return &ort_api_1_to_20;

    fprintf(stderr,
            "The requested API version [%u] is not available, only API versions [1, %u] are supported in this build."
            " Current ORT Version is: %s\n",
            version, ORT_API_VERSION, ORT_VERSION);

    return nullptr;  // Unsupported version
  }

OrtApi
------

It is a struct containing lots of function pointers. It is initialized
in `<https://github.com/microsoft/onnxruntime/blob/main/onnxruntime/core/session/onnxruntime_c_api.cc#L2399>`_

.. code-block:: c++

  static constexpr OrtApi ort_api_1_to_20 = {
      // NOTE: The ordering of these fields MUST not change after that version has shipped since existing binaries depend on this ordering.

      // Shipped as version 1 - DO NOT MODIFY (see above text for more information)
      &OrtApis::CreateStatus,
      &OrtApis::GetErrorCode,
      &OrtApis::GetErrorMessage,

  ...
  };

The initialized function pointers are declared in `<https://github.com/microsoft/onnxruntime/blob/main/onnxruntime/core/session/ort_apis.h>`_


OrtStatus
---------

It is defined in `<https://github.com/microsoft/onnxruntime/blob/main/onnxruntime/core/framework/error_code.cc#L12>`_

.. code-block:: c++

  struct OrtStatus {
    OrtErrorCode code;
    char msg[1];  // a null-terminated string
  };

So usually a pointer to it is used. The way to create a pointer to it is given
in `<https://github.com/microsoft/onnxruntime/blob/main/onnxruntime/core/framework/error_code.cc#L24>`_

.. code-block:: c++

  inline OrtStatus* NewStatus(size_t clen) {
    auto* buf = new (std::nothrow) uint8_t[sizeof(OrtStatus) + clen];
    if (buf == nullptr) return nullptr;  // OOM. What we can do here? abort()?
    return new (buf) OrtStatus;
  }

Note that if uses placement new.

Its usage is given below:

CreateStatus
~~~~~~~~~~~~

.. code-block:: c++

  // https://github.com/microsoft/onnxruntime/blob/main/onnxruntime/core/framework/error_code.cc

  // Even we say it may not return NULL, indeed it may.
  _Check_return_ _Ret_notnull_ OrtStatus* ORT_API_CALL OrtApis::CreateStatus(OrtErrorCode code,
                                                                             _In_z_ const char* msg) NO_EXCEPTION {
    assert(!(code == 0 && msg != nullptr));
    SafeInt<size_t> clen(nullptr == msg ? 0 : strnlen(msg, onnxruntime::kMaxStrLen));
    OrtStatus* p = NewStatus(clen);
    if (p == nullptr)
      return nullptr;
    p->code = code;
    memcpy(p->msg, msg, clen);
    p->msg[clen] = '\0';
    return p;
  }

ReleaseStatus
~~~~~~~~~~~~~

We need to free the pointer after using it to avoid memory leak.

``struct OrtApi`` provides two function pointers to create and release ``OrtStatus``:

.. code-block:: c++

  OrtStatus*(ORT_API_CALL* CreateStatus)(OrtErrorCode code, _In_ const char* msg)NO_EXCEPTION ORT_ALL_ARGS_NONNULL;

  ORT_CLASS_RELEASE(Status);

where ``ORT_CLASS_RELEASE`` is a macro and is defined as:

.. code-block:: c++

  #define ORT_CLASS_RELEASE(X) void(ORT_API_CALL * Release##X)(_Frees_ptr_opt_ Ort##X * input)

.. code-block:: c++

  // https://github.com/microsoft/onnxruntime/blob/main/onnxruntime/core/framework/error_code.cc

  ORT_API(void, OrtApis::ReleaseStatus, _Frees_ptr_opt_ OrtStatus* value) { delete[] reinterpret_cast<uint8_t*>(value); }


OrtErrorCode
------------

``OrtErrorCode`` is defined in `<https://github.com/microsoft/onnxruntime/blob/main/include/onnxruntime/core/session/onnxruntime_c_api.h#L245>`_

.. code-block:: bash

  typedef enum OrtErrorCode {
    ORT_OK,
    ORT_FAIL,
    ORT_INVALID_ARGUMENT,
    ORT_NO_SUCHFILE,
    ORT_NO_MODEL,
    ORT_ENGINE_ERROR,
    ORT_RUNTIME_EXCEPTION,
    ORT_INVALID_PROTOBUF,
    ORT_MODEL_LOADED,
    ORT_NOT_IMPLEMENTED,
    ORT_INVALID_GRAPH,
    ORT_EP_FAIL,
  } OrtErrorCode;

GetApi
------

It is defined in ``onnxruntime_cxx_api.h``. The function returns a global variable.
We can use a macro to control how this global variable is initialized.

If the macro ``ORT_API_MANUAL_INIT`` is defined, then we have to invoke ``InitApi()``
by ourselves. We can also invoke an overload version ``InitApi(const OrtApi* api) noexcept``.

By default, ``ORT_API_MANUAL_INIT`` is not defined and we have

.. code-block:: c++

  template <typename T>
  const OrtApi* Global<T>::api_ = OrtGetApiBase()->GetApi(ORT_API_VERSION);


.. code-block:: c++

  /// This returns a reference to the OrtApi interface in use
  inline const OrtApi& GetApi() noexcept { return *Global<void>::api_; }

Note that it uses a global variable template.

OrtAllocator
------------

In the C++ code of onnxruntime, there is a macro ``USE_MIMALLOC``. If it is defined, then
`<https://github.com/microsoft/mimalloc>`_ is used.

During allocation, the return pointer is ensured to be ``xx`` bytes aligned,
where ``xx`` is a constant.
