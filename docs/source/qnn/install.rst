Install qnn
============

.. code-block:: bash

  wget https://apigwx-aws.qualcomm.com/qsc/public/v1/api/download/software/sdks/Qualcomm_AI_Runtime_Community/All/2.32.0.250228/v2.32.0.250228.zip

  wget https://softwarecenter.qualcomm.com/api/download/software/qualcomm_neural_processing_sdk/v2.26.2.240911.zip

  wget https://apigwx-aws.qualcomm.com/qsc/public/v1/api/download/software/sdks/Qualcomm_AI_Runtime_Community/All/2.39.0.250926/v2.39.0.250926.zip
  unzip v2.39.0.250926.zip

.. code-block::

  Archive:  ./v2.39.0.250926.zip
     creating: qairt/
     creating: qairt/2.39.0.250926/
     creating: qairt/2.39.0.250926/benchmarks/
     creating: qairt/2.39.0.250926/benchmarks/QNN/

.. code-block::

   cd qairt/2.39.0.250926/
   cd bin
   source ./envsetup.sh

.. code-block::

  [INFO] QAIRT_SDK_ROOT=/star-fj/fangjun/download/qnn/qairt/2.39.0.250926
  [WARN] QNN_SDK_ROOT/SNPE_ROOT set to QAIRT_SDK_ROOT for backwards compatibility and will be deprecated in a future release.
  [INFO] QAIRT SDK environment setup complete

.. code-block::

  $ echo $QAIRT_SDK_ROOT
  /star-fj/fangjun/download/qnn/qairt/2.39.0.250926

  $ echo $QNN_SDK_ROOT
  /star-fj/fangjun/download/qnn/qairt/2.39.0.250926

.. code-block::

   sudo ./check-linux-dependency.sh

For android::

  sdkmanager --list | grep ndk
  sdkmanager "ndk;26.2.11394342"

.. code-block::

   [==========                             ] 26% Downloading android-ndk-r26c-linux


.. code-block::

   libc++.so.1: cannot open shared object file: No such file or directory

   sudo apt install libc++-dev libc++abi-dev
   # Installed inside /usr

   ImportError: libunwind.so.1: cannot open shared object file: No such file or directory

   sudo apt install libunwind8 libunwind-dev


