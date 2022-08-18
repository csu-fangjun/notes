Installation
============

Install NDK on Linux
--------------------

See `<https://developer.android.com/ndk/downloads/index.html>`_

See `<https://www.cryptopp.com/wiki/Android_Setup_(Command_Line)>`_ for details.

.. code-block:: bash

   wget https://dl.google.com/android/repository/android-ndk-r25-linux.zip
   unzip -d /ceph-fj/fangjun/software android-ndk-r25-linux.zip
   # It will create /ceph-fj/fangjun/software/android-ndk-r25

Other versions can be downloaded from `<https://github.com/android/ndk/wiki/Unsupported-Downloads>`_

.. code-block:: bash

   wget https://dl.google.com/android/repository/android-ndk-r24-linux.zip
   unzip -d /ceph-fj/fangjun/software android-ndk-r24-linux.zip

   # It will create /ceph-fj/fangjun/software/android-ndk-r24

Now create a symlink in ``/ceph-fj/fangjun/software``:

.. code-block:: bash

   cd /ceph-fj/fangjun/software
   ln -s android-ndk-r25 android-ndk

Set the following environment variable:

.. code-block:: bash

   export ANDROID_NDK_ROOT=/ceph-fj/fangjun/software/android-ndk
   export PATH=$ANDROID_NDK_ROOT:$PATH

Install SDK on Linux
--------------------

Download the commandline tools only from `<https://developer.android.com/studio#downloads>`_

.. code-block:: bash

   wget https://dl.google.com/android/repository/commandlinetools-linux-8512546_latest.zip
   unzip -d /ceph-fj/fangjun/software/android-sdk ./commandlinetools-linux-8512546_latest.zip
   # Everything is inside /ceph-fj/fangjun/software/android-sdk/cmdline-tools/
   cd /ceph-fj/fangjun/software/android-sdk
   mv cmdline-tools latest
   mkdir cmdline-tools
   mv latest ./cmdline-tools/

If we don't run ``mv cmdline-tools latest``, it will throw the following error

.. code-block:: bash

  $ /ceph-fj/fangjun/software/android-sdk/cmdline-tools/bin/sdkmanager --list

  Error: Could not determine SDK root.
  Error: Either specify it explicitly with --sdk_root= or move this package into its expected location: <sdk>/cmdline-tools/latest/

Set the following environment variable:

.. code-block:: bash

   export ANDROID_SDK_ROOT=/ceph-fj/fangjun/software/android-sdk/cmdline-tools
   export PATH=$ANDROID_SDK_ROOT/latest/bin:$PATH

   export ANDROID_HOME=/ceph-fj/fangjun/software/android-sdk/cmdline-tools

.. code-block:: bash

   sdkmanager --update
   sdkmanager --list

   # Install the build tools
   sdkmanager "platforms;android-28" "build-tools;28.0.3"
   # It will create the following directories inside /ceph-fj/fangjun/software/android-sdk/
   #
   # build-tools, emulator, licenses, patcher, platform-tools, platforms, tools
