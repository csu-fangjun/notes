cmake
=====

See

  - `<https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html>`_
  - `<https://developer.android.com/ndk/guides/cmake#command-line>`_
  - ``/ceph-fj/fangjun/software/android-ndk/build/cmake/android.toolchain.cmake``

User provided:

  - ``ANDROID_NDK``: Set to the path of ``android-ndk``
  - ``ANDROID_ABI``: ``armeabi-v7a``, ``arm64-v8a``, ``x86``, ``x86_64``,
  - ``ANDROID_PLATFORM``
  - ``ANDROID_NATIVE_API_LEVEL``
  - ``ANDROID_TOOLCHAIN``
  - ``ANDROID``: ``TRUE``
  - ``CMAKE_SYSTEM_NAME``: ``Anroid``
  - ``ANDROID_STL``
  - ``ANDROID_HOST_TAG``


Auto generated:

  - ``ANDROID_NDK_MAJOR`` - see ``android-ndk/source.properties``
  - ``ANDROID_NDK_MINOR`` - see ``android-ndk/source.properties``
  - ``ANDROID_NDK_BUILD`` - see ``android-ndk/source.properties``
  - ``ANDROID_NDK_REVISION`` - see ``android-ndk/source.properties``
  - ``ANDROID_TOOLCHAIN_ROOT``
  - ``ANDROID_C_COMPILER``
