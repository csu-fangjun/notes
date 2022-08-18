hello
=====

In this note, we describe how to build an executable, how to create
an emulator, and how to run the executable in the emulator via ``adb push``,
``adb shell``.


.. literalinclude:: ./code/hello/hello.cc
   :language: c++
   :linenos:
   :caption: ./code/hello/hello.cc

.. literalinclude:: ./code/hello/CMakeLists.txt
   :language: cmake
   :linenos:
   :caption: ./code/hello/CMakeLists

x86
---

.. code-block:: bash

  export ANDROID_NDK_ROOT=/ceph-fj/fangjun/software/android-ndk
  cmake -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_ROOT/build/cmake/android.toolchain.cmake -DANDROID_ABI=x86 ..

Other values:
  - ``-DANDROID_ABI="arm64-v8a"``
  - ``-DANDROID_ABI="armeabi-v7a"``

  - ``-DANDROID_ARM_NEON=ON``

  - ``-DANDROID_PLATFORM=android-21``
  - ``-DANDROID_PLATFORM=android-24``

.. code-block:: bash

  $ sdkmanager --list | grep system-images | grep x86 | grep android-28
  $ sdkmanager "system-images;android-28;default;x86"

  $ which avdmanager
  /ceph-fj/fangjun/software/android-sdk/cmdline-tools/latest/bin/avdmanage

  $ avdmanager create avd --help
  $ -k --package  : Package path of the system image for this AVD
  #                 (e.g., 'system-images;android-19;google_apis;x86').
  # -n --name     : Name of the new AVD [required]
  # -b --abi      : The ABI to use for the AVD. The default is to auto-select
  #                 the ABI if the platform has only one ABI for its system images
  # -g --tag      : The sys-img tag to use for the AVD. The default is to
  #                 auto-select if the platform has only one tag for its system
  #                 images
  $ avdmanager create avd -k "system-images;android-28;default;x86" -n hello -b x86 -g default
  # Use the default option [no] when it prompts:
  #  Do you wish to create a custom hardware profile? [no]
  #
  $ avdmanager delete avd -n hello # to delete it

.. code-block:: bash

  $ avdmanager list avd
  Available Android Virtual Devices:
      Name: hello
      Path: /root/fangjun/.android/avd/hello.avd
    Target: Default Android System Image
            Based on: Android 9.0 (Pie) Tag/ABI: default/x86
    Sdcard: 512 MB

.. code-block:: bash

  emulator -avd hello -no-window  -no-accel # then, open a new terminal

.. code-block:: bash
  $ adb devices

  * daemon not running; starting now at tcp:5037
  * daemon started successfully
  List of devices attached
  emulator-5554   offline

.. code-block:: bash

   # push the binary from code/hello/build/hello

   adb push ./code/hello/build/hello /sdcard # not able to use chmod +x in it
   adb push ./code/hello/build/hello /data/local
   adb shell /data/local/hello
   adb shell
   generic_x86:/ #

.. code-block:: bash

  generic_x86:/ # ./data/local/hello
  hello world
