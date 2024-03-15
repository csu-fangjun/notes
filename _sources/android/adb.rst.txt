adb
===

install on macos
-----------------

.. code-block:: bash

   wget https://dl.google.com/android/repository/platform-tools-latest-darwin.zip
   # unzip it and you will find the binary `adb`

install on windows
------------------

Go to `<https://adbshell.com/downloads>`_ to download it.

install on Linux
----------------

.. code-block:: bash

   wget https://dl.google.com/android/repository/platform-tools-latest-linux.zip
   # unzip it

run binaries
------------

.. code-block:: bash

  adb push ./hello-world /data/local/tmp/

paste text to android emulator
------------------------------

.. code-block:: bash

   adb shell "input text 'hello world'"


