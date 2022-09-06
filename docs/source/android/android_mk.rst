Android.mk
==========

See `<https://developer.android.com/ndk/guides/android_mk>`_

hello
-----

.. literalinclude:: ./code/android_mk/hello/jni/foo.cc
   :language: c++
   :linenos:
   :caption: ./code/android_mk/hello/jni/foo.cc


.. literalinclude:: ./code/android_mk/hello/jni/Android.mk
   :language: makefile
   :linenos:
   :caption: ./code/android_mk/hello/jni/Android.mk

.. literalinclude:: ./code/android_mk/hello/jni/Application.mk
   :language: makefile
   :linenos:
   :caption: ./code/android_mk/hello/jni/Application.mk

``APP_STL := c++_shared`` is to fix the following errors:

.. code-block::

  ld: error: undefined symbol: std::__ndk1::cout

To compile:

.. code-block:: bash

   cd code/android_mk/hello
   ndk-build

It will generate two directories in ``hello``: ``libs`` and ``obj``..

.. code-block:: bash

   adb push libs/x86/foo /data/local
   adb push libs/x86/libc++_shared.so /data/local
   adb shell
   cd /data/local
   export LD_LIBRARY_PATH=.
   ./foo
