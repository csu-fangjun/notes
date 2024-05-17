Install
=======

1. Visit `<https://dart.dev/get-dart>`_
2. We use `<https://dart.dev/get-dart/archive>`_

.. code-block:: bash

   wget https://storage.googleapis.com/dart-archive/channels/stable/release/3.4.0/sdk/dartsdk-macos-x64-release.zip

.. code-block::

  -rw-r--r--  1 fangjun  staff   221M May 15 11:40 dartsdk-macos-x64-release.zip

.. code-block:: bash

   cd ~/software
   unzip ~/Downloads/dartsdk-macos-x64-release.zip

   # It will create a directory ~/software/dart-sdk
   rm ~/Downloads/dartsdk-macos-x64-release.zip

   export PATH=/Users/fangjun/software/dart-sdk/bin:$PATH

.. code-block:: bash

  (py38) fangjuns-MacBook-Pro:software fangjun$ dart --version
  Dart SDK version: 3.4.0 (stable) (Mon May 6 07:59:58 2024 -0700) on "macos_x64"

  (py38) fangjuns-MacBook-Pro:software fangjun$ which dart
  /Users/fangjun/software/dart-sdk/bin/dart

codefmt in vim
--------------

.. code-block:: bash

   # in the terminal, run
   alias dartfmt="dart format"

Install Dart plugin in IntelliJ IDEA
------------------------------------

Name of the plugin is ``Dart``. It has more than ``18.8M`` downloads.
