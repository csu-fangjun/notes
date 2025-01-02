Flutter
=======

Create a project from the command line::

  flutter create my_app

will create a directory ``my_app`` in the current directory.

recording
---------

`<https://github.com/Picovoice/flutter-voice-processor>`_ supports only Android and iOS.
It is used in `<https://github.com/Picovoice/porcupine/tree/master/binding/flutter>`_.

`<https://github.com/llfbandit/record/blob/master/record/pubspec.yaml>`_ is a good candidate since
it supports many platforms. It uses `<https://github.com/flutter/packages/blob/main/packages/plugin_platform_interface/lib/plugin_platform_interface.dart>`_ to define an interface for different platforms.

