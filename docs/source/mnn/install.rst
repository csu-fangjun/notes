Install
=======

Refer to
`<https://mnn-docs.readthedocs.io/en/latest/compile/engine.html>`_

.. code-block:: bash

   ./schema/generate.sh
   mkdir build
   cd build
   cmake  -DMNN_BUILD_CONVERTER=ON -DMNN_SUPPORT_DEPRECATED_OP=OFF -DMNN_BUILD_TORCH=ON ..
   make -j 10

Some changes:

.. code-block:: diff

  diff --git a/CMakeLists.txt b/CMakeLists.txt
  index 10071c7c..bab93ac9 100644
  --- a/CMakeLists.txt
  +++ b/CMakeLists.txt
  @@ -40,8 +40,8 @@ option(MNN_BUILD_DEMO "Build demo/exec or not" OFF)
   option(MNN_BUILD_TOOLS "Build tools/cpp or not" ON)
   option(MNN_BUILD_QUANTOOLS "Build Quantized Tools or not" OFF)
   option(MNN_EVALUATION "Build Evaluation Tools or not" OFF)
  -option(MNN_BUILD_CONVERTER "Build Converter" OFF)
  -option(MNN_SUPPORT_DEPRECATED_OP "Enable MNN's tflite quantized op" ON)
  +option(MNN_BUILD_CONVERTER "Build Converter" ON)
  +option(MNN_SUPPORT_DEPRECATED_OP "Enable MNN's tflite quantized op" OFF)
   option(MNN_DEBUG_MEMORY "MNN Debug Memory Access" OFF)
   option(MNN_DEBUG_TENSOR_SIZE "Enable Tensor Size" OFF)
   option(MNN_GPU_TRACE "Enable MNN Gpu Debug" OFF)
  @@ -444,6 +444,8 @@ if (NOT MSVC)
       set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstrict-aliasing -ffunction-sections -fdata-sections -ffast-math")
   endif()

  +set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -D_GLIBCXX_USE_CXX11_ABI=0 ")
  +
   # Metal
   set(MNN_DEPS "")
   set(MNN_EXTRA_DEPENDS "")

  diff --git a/tools/converter/CMakeLists.txt b/tools/converter/CMakeLists.txt
  index a00b7596..d5dff481 100644
  --- a/tools/converter/CMakeLists.txt
  +++ b/tools/converter/CMakeLists.txt
  @@ -2,7 +2,7 @@ IF(MNN_BUILD_CONVERTER)
     SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../../)
     option(TF_CONVERT_ORIGIN "Fall Back to Origin Model Converter" OFF)
     option(TFMODEL_OPTIMIZE "Enable tensorflow model optimizer" OFF)
  -  option(MNN_BUILD_TORCH "Build Converter support TorchScript." OFF)
  +  option(MNN_BUILD_TORCH "Build Converter support TorchScript." ON)
     IF(MNN_BUILD_PROTOBUFFER)
         SET(Protobuf_LIBRARIES libprotobuf)
         include_directories(${CMAKE_CURRENT_LIST_DIR}/../../3rd_party/protobuf/src)

  diff --git a/tools/converter/source/torch/CMakeLists.txt b/tools/converter/source/torch/CMakeLists.txt
  index e8eca41e..9b9abf85 100644
  --- a/tools/converter/source/torch/CMakeLists.txt
  +++ b/tools/converter/source/torch/CMakeLists.txt
  @@ -1,7 +1,7 @@
   file(GLOB TORCH_SRC ${CMAKE_CURRENT_LIST_DIR}/*.cpp ${CMAKE_CURRENT_LIST_DIR}/*.hpp)
   add_library(MNNConverterTorch OBJECT ${TORCH_SRC})

  -IF (CMAKE_SYSTEM_NAME MATCHES "Linux" AND "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  +IF (NOT CMAKE_SYSTEM_NAME MATCHES "Linux" AND "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
       SET(LIB_TORCH_PATH "${CMAKE_CURRENT_BINARY_DIR}/libtorch/share/cmake")
       IF (EXISTS "/etc/redhat-release")
           # redhat force _GLIBCXX_USE_CXX11_ABI=0
