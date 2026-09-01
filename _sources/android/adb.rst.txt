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

Frequently used commands
------------------------

.. code-block:: bash

   adb kill-server
   adb start-server
   adb devices
   adb devices -l


``adb devices``::

  List of devices attached
  192.168.65.204:44959    device
  adb-RFARA0X7Z9Y-qzseiX._adb-tls-connect._tcp.   device

``adb devices -l``::

  List of devices attached
  192.168.65.204:44959   device product:freshbscn model:SM_R860 device:freshbs transport_id:3
  adb-RFARA0X7Z9Y-qzseiX._adb-tls-connect._tcp. device product:freshbscn model:SM_R860 device:freshbs transport_id:1

pair a device via wireless
--------------------------
.. code-block:: bash

  # the port is different from the port when connecting to the device

  adb pair 192.168.65.204:36029

It will show::

  Enter pairing code: 156066

and::

  Successfully paired to 192.168.65.204:36029 [guid=adb-RFARA0X7Z9Y-qzseiX]

connect a device
----------------

.. code-block:: bash

  # the port is different from the port when pairing with the device
  ad connect 192.168.65.204:44959

It will show::

  connected to 192.168.65.204:44959

run binaries
------------

.. code-block:: bash

  adb push ./hello-world /data/local/tmp/

paste text to android emulator
------------------------------

.. code-block:: bash

   adb shell "input text 'hello world'"

Install an apk
--------------

.. code-block:: bash

   adb -e install path/to/app.apk

   # Install to a specific device
   adb -s <DEVICE ID> install <PATH TO APK>



