Install
=======

To install the flutter SDK,

  1. Visit `<https://docs.flutter.dev/get-started/install>`_
  2. For macOS, download ``flutter_macos_3.22.0-stable.zip``

    .. code-block:: bash

       cd ~/software
       unzip /Users/fangjun/Downloads/flutter_macos_3.22.0-stable.zip
       export PATH=/Users/fangjun/software/flutter/bin:$PATH

  3. It also installs ``dart``. There is no need to install ``dart`` separately.
  4. Open Android Studio, and install the ``flutter`` plugin

      - Android studio settings, Plugins, Marketplace, search for ``flutter``, click install
      - Install required plugings (the  flutter plugin requires Dart to be installed), install
      - Restart IDE
      - Click File, New, New Flutter Project..

  4. ``export ANDROID_HOME=/Users/fangjun/software/my-android``
       or use `` flutter config --android-sdk /Users/fangjun/software/my-android/``

  5. In the terminal, run ``flutter doctor -v``.

    .. code-block::

      [✓] Flutter (Channel stable, 3.22.0, on macOS 13.1 22C65 darwin-x64, locale en-CN)
          • Flutter version 3.22.0 on channel stable at /Users/fangjun/software/flutter
          • Upstream repository https://github.com/flutter/flutter.git
          • Framework revision 5dcb86f68f (8 days ago), 2024-05-09 07:39:20 -0500
          • Engine revision f6344b75dc
          • Dart version 3.4.0
          • DevTools version 2.34.3

      [!] Android toolchain - develop for Android devices (Android SDK version 34.0.0)
          • Android SDK at /Users/fangjun/software/my-android
          • Platform android-34, build-tools 34.0.0
          • ANDROID_HOME = /Users/fangjun/software/my-android
          • Java binary at: /Applications/Android Studio.app/Contents/jbr/Contents/Home/bin/java
          • Java version OpenJDK Runtime Environment (build 17.0.10+0-17.0.10b1087.21-11572160)
          ! Some Android licenses not accepted. To resolve this, run: flutter doctor --android-licenses

      [!] Xcode - develop for iOS and macOS (Xcode 14.2)
          • Xcode at /Applications/Xcode.app/Contents/Developer
          • Build 14C18
          ! Flutter recommends a minimum Xcode version of 15.
            Download the latest version or update via the Mac App Store.
          ✗ CocoaPods not installed.
              CocoaPods is used to retrieve the iOS and macOS platform side's plugin code that responds to your plugin usage on the Dart side.
              Without CocoaPods, plugins will not work on iOS or macOS.
              For more info, see https://flutter.dev/platform-plugins
            To install see https://guides.cocoapods.org/using/getting-started.html#installation for instructions.

      [✓] Chrome - develop for the web
          • Chrome at /Applications/Google Chrome.app/Contents/MacOS/Google Chrome

      [✓] Android Studio (version 2023.3)
          • Android Studio at /Applications/Android Studio.app/Contents
          • Flutter plugin can be installed from:
            🔨 https://plugins.jetbrains.com/plugin/9212-flutter
          • Dart plugin can be installed from:
            🔨 https://plugins.jetbrains.com/plugin/6351-dart
          • Java version OpenJDK Runtime Environment (build 17.0.10+0-17.0.10b1087.21-11572160)

      [✓] IntelliJ IDEA Community Edition (version 2024.1.1)
          • IntelliJ at /Applications/IntelliJ IDEA CE.app
          • Flutter plugin can be installed from:
            🔨 https://plugins.jetbrains.com/plugin/9212-flutter
          • Dart plugin version 241.15989.9
      [✓] Connected device (2 available)
          • macOS (desktop) • macos  • darwin-x64     • macOS 13.1 22C65 darwin-x64
          • Chrome (web)    • chrome • web-javascript • Google Chrome 125.0.6422.60

      [✓] Network resources
          • All expected network resources are available.

      ! Doctor found issues in 2 categories.

  6. In the terminal, run ``flutter doctor --android-licenses``.

  7. for macos

    .. code-block::

      sudo sh -c 'xcode-select -s /Applications/Xcode.app/Contents/Developer && xcodebuild -runFirstLaunch'
      sudo xcodebuild -license
      sudo gem install cocoapods
