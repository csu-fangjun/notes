#!/usr/bin/env bash
set -ex


dir=$PWD/build-android-arm64-v8a

mkdir -p $dir
cd $dir

if [ -z $ANDROID_NDK ]; then
  # For macOS, I have installed Android Studio, select the menu
  # Tools -> SDK manager -> Android SDK
  # and set "Android SDK location" to /Users/fangjun/software/my-android/sdk
  ANDROID_NDK=/Users/fangjun/software/my-android/sdk/ndk/29.0.14206865
fi

if [ ! -d $ANDROID_NDK ]; then
  echo Please set the environment variable ANDROID_NDK before you run this script
  exit 1
fi
$ANDROID_NDK/ndk-build --help

cmake -DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK/build/cmake/android.toolchain.cmake" \
    -DCMAKE_INSTALL_PREFIX=./install \
    -DANDROID_ABI="arm64-v8a" \
    -DANDROID_PLATFORM=android-28 ..
make
