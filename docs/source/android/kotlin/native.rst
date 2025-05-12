Kotlin Native
=============

See

 - `<https://kotlinlang.org/docs/native-get-started.html>`_
 - `<https://github.com/kgit2/c-interop-klib>`_
- `<https://github.com/Kotlin/kmp-native-wizard>`_

Go to `<https://github.com/JetBrains/kotlin/releases/tag/v2.1.20>`_, download
``kotlin-native-prebuilt-macos-x86_64-2.1.20.tar.gz``. Unzip it and put its ``bin``
to the ``PATH``::

  export PATH=/Users/fangjun/software/


.. literalinclude:: ./code/native/hello.kt
   :language: kotlin
   :caption: ./code/native/hello.kt

.. code-block:: bash

   kotlinc-native ./hello.kt -o hello

Next, we can run ``./hello.kexe``.



sherpa-onnx
-----------

The ``sherpa-onnx-c-api.def`` file::

  headers = sherpa-onnx/c-api/c-api.h
  headerFilter = sherpa-onnx/c-api/c-api.h
  compilerOpts = -I /Users/fangjun/open-source/sherpa-onnx
  package = sherpa_onnx
  linkerOpts = -L /Users/fangjun/open-source/sherpa-onnx/build/lib -lsherpa-onnx-c-api

The ``main.kt``::

  import kotlinx.cinterop.*
  import sherpa_onnx.*

  fun main() {
    print("hello")
  }

The command::

  cinterop -def ./sherpa-onnx-c-api.def -o libsherpa_onnx_c_api.klib
  kotlinc-native  ./main.kt -l   libsherpa_onnx_c_api.klib

  # a.txt contains the kotlin code for our c api
  klib dump-metadata ./libsherpa_onnx_c_api.klib -print-signatures true > a.txt

char
----

In C ``extern usigned char my_c_byte``.

In kotlin, there is a implicit ``extern var my_c_byte: ByteVar``.
The variable type in Kotlin is ``ByteVar``.

.. code-block::

   var bytePtr: NativePtr = my_c_byte.ptr

   // Note: bytePtr.pointed == my_c_byte

   // Read it
   val byteValue: Byte = bytePtr.pointed.value

   // Change it
   bytePtr.pointed.value = 0x42

   // Read it again
   val newByteValue: Byte = bytePtr.pointed.value
