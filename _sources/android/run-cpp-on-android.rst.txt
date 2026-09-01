Run CPP on Android
===================

.. literalinclude:: ./code/run-cpp-on-android/main.cc

.. literalinclude:: ./code/run-cpp-on-android/CMakeLists.txt

.. literalinclude:: ./code/run-cpp-on-android/build-android-arm64-v8a.sh


- 1. On PC, Run ``./build-android-arm64-v8a.sh``
- 2. On PC, run  ``adb push build-android-arm64-v8a/qnn-demo  /data/local/tmp/``
- 3. On PC, run ``adb shell``
- 4. On phone, run::

  cd /data/local/tmp
  ./qnn-demo

