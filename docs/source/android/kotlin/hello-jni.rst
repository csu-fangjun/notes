Hello jni
=========

References:

  - `<https://matt-moore.medium.com/kotlin-jni-for-native-code-835e93af7ddf>`_
  - `<https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/functions.html>`_
  - `<https://developer.android.com/training/articles/perf-jni.html#primitive-arrays>`_

.. literalinclude:: ./code/jni/hello/Makefile
   :language: makefile
   :caption: ./code/jni/hello/Makefile


**Note**: We have to disable name mangling here.

`<https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/design.html>`_
describe the specification:

  - ``Java_NativeSample_sayHello``: The prefix is fixed with ``Java``.
    ``NativeSample`` is the class name in kotlin. ``sayHello`` is the method
    in kotlin.


.. literalinclude:: ./code/jni/hello/hello.h
   :language: c++
   :caption: ./code/jni/hello/hello.h

The first argument must be ``JNIEnv *env``. Since it is a non-static kotlin method,
the second argument is a reference to the object. Otherwise, it is a reference
to the class.

.. literalinclude:: ./code/jni/hello/hello.cc
   :language: c++
   :caption: ./code/jni/hello/hello.cc

``System.loadLibrary("hello")``:

  - On Linux, it looks for ``libhello.so``
  - On Windows, it looks for ``hello.dll``

``external fun sayHello()``:

  - It will look for the function with name ``Java_NativeSample_sayHello``.

.. literalinclude:: ./code/jni/hello/NativeSample.kt
   :language: java
   :caption: ./code/jni/hello/NativeSample.kt

.. literalinclude:: ./code/jni/hello/Main.kt
   :language: java
   :caption: ./code/jni/hello/Main.kt
