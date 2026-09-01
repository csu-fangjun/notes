ffi
===

Note there are two ffi packages:

  - 1. One is builtin: ``dart:ffi``
  - 2. One is ``package:ffi/ffi.dart`` `<https://pub.dev/documentation/ffi/latest/ffi/ffi-library.html>`_

Doc for ``dart:io``:

  - `<https://dart.dev/libraries/dart-io>`_
  - `<https://api.dart.dev/stable/3.4.0/dart-io/dart-io-library.html>`_

Doc for ``dart:ffi``: `<https://api.dart.dev/stable/3.4.0/dart-ffi/dart-ffi-library.html>`_

Examples for ``ffi``: `<https://github.com/dart-lang/samples/tree/main/ffi>`_


types
-----

- ``char -> Char``
- ``double -> Double``
- ``float -> Float``
- ``int -> Int``
- ``int8 -> Int8``
- ``int16 -> Int16``
- ``int32 -> Int32``
- ``int64 -> Int64``
- ``intptr_t -> IntPtr``
- ``long -> Long``

.. code-block:: dart

   // void xxx();
   typedef HelloWorldFunc = ffi.Void Function();


.. code-block:: bash

   # create a pluggin
   flutter create --template=plugin --platforms=android,ios mybatteryplugin


.. literalinclude:: ./code/ffi/a.h
   :language: dart
   :linenos:
   :caption: ./code/ffi/a.h

.. literalinclude:: ./code/ffi/a.cc
   :language: dart
   :linenos:
   :caption: ./code/ffi/a.cc

.. literalinclude:: ./code/ffi/hello.dart
   :language: dart
   :linenos:
   :caption: ./code/ffi/hello.dart

.. literalinclude:: ./code/ffi/pubspec.yaml
   :language: yaml
   :linenos:
   :caption: ./code/ffi/pubspec.yaml

.. literalinclude:: ./code/ffi/run.sh
   :language: bash
   :linenos:
   :caption: ./code/ffi/run.sh
