Installation
============

CUDA 10.1.243
-------------

.. code-block:: bash

  ./cuda_10.1.243_418.87.00_linux.run --silent --toolkit --installpath=/ceph-data4/fangjun/software/cuda-10.1.243 --no-opengl-libs --no-drm --no-man-page

  # Install cuDNN
  cd /ceph-data4/fangjun/software/cuda-10.1.243
  tar xvf /ceph-sh0/fangjun/cudnn/cudnn-10.1-linux-x64-v8.0.4.30.tgz --strip-components=1

.. code-block:: bash

  #!/usr/bin/env bash

  export CUDA_HOME=/ceph-data4/fangjun/software/cuda-10.1.243
  export PATH=$CUDA_HOME/bin:$PATH
  export LD_LIBRARY_PATH=$CUDA_HOME/lib64:$LD_LIBRARY_PATH

  # See /ceph-fj/fangjun/py38/lib/python3.8/site-packages/torch/share/cmake/Caffe2/Modules_CUDA_fix/upstream/FindCUDA.cmake
  export CUDA_TOOLKIT_ROOT_DIR=$CUDA_HOME
  export CUDA_TOOLKIT_ROOT=$CUDA_HOME
  export CUDA_BIN_PATH=$CUDA_HOME
  export CUDA_PATH=$CUDA_HOME
  export CUDA_INC_PATH=$CUDA_HOME/targets/x86_64-linux

CUDA 10.2.89
------------

.. code-block:: bash

  ./cuda_10.2.89_440.33.01_linux.run --silent --toolkit --installpath=/ceph-data4/fangjun/software/cuda-10.2.89 --no-opengl-libs --no-drm --no-man-page
  # Install cuDNN
  wget https://huggingface.co/csukuangfj/cudnn/resolve/main/cudnn-10.2-linux-x64-v8.0.2.39.tgz
  tar xvf cudnn-10.2-linux-x64-v8.0.2.39.tgz --strip-components=1 -C /ceph-data4/fangjun/software/cuda-10.2.89

.. code-block:: bash

  #!/usr/bin/env bash

  export CUDA_HOME=/ceph-sh1/fangjun/software/cuda-10.2.89
  export PATH=$CUDA_HOME/bin:$PATH
  export LD_LIBRARY_PATH=$CUDA_HOME/lib64:$LD_LIBRARY_PATH
  export LD_LIBRARY_PATH=$CUDA_HOME/lib:$LD_LIBRARY_PATH

  # See /ceph-fj/fangjun/py38/lib/python3.8/site-packages/torch/share/cmake/Caffe2/Modules_CUDA_fix/upstream/FindCUDA.cmake
  export CUDA_TOOLKIT_ROOT_DIR=$CUDA_HOME
  export CUDA_TOOLKIT_ROOT=$CUDA_HOME
  export CUDA_BIN_PATH=$CUDA_HOME
  export CUDA_PATH=$CUDA_HOME
  export CUDA_INC_PATH=$CUDA_HOME/targets/x86_64-linux
  export CFLAGS=-I$CUDA_HOME/targets/x86_64-linux/include


CUDA 11.0.3
------------

.. code-block:: bash

  ./cuda_11.0.3_450.51.06_linux.run --silent --toolkit --installpath=/ceph-data4/fangjun/software/cuda-11.0.3 --no-opengl-libs --no-drm --no-man-page

  # Install cuDNN
  cd /ceph-data4/fangjun/software/cuda-11.0.3
  tar xvf /ceph-sh0/fangjun/cudnn/cudnn-11.0-linux-x64-v8.0.4.30.tgz --strip-components=1

CUDA 11.3.1
-----------

.. code-block:: bash

  ./cuda_11.3.1_465.19.01_linux.run --silent --toolkit --installpath=/ceph-data4/fangjun/software/cuda-11.3.1 --no-opengl-libs --no-drm --no-man-page
  cd /ceph-data4/fangjun/software/cuda-11.3.1
  tar xvf /ceph-sh0/fangjun/cudnn/cudnn-11.3-linux-x64-v8.2.1.32.tgz --strip-components=1

CUDA 11.5.2
-----------

.. code-block:: bash

  ./cuda_11.5.2_495.29.05_linux.run --silent --toolkit --installpath=/ceph-data4/fangjun/software/cuda-11.5.2 --no-opengl-libs --no-drm --no-man-page
  cd /ceph-data4/fangjun/software/cuda-11.5.2
  tar xvf /ceph-sh0/fangjun/cudnn/cudnn-linux-x86_64-8.3.2.44_cuda11.5-archive.tar.xz --strip-components=1


CUDA 11.6.1
-----------

.. code-block:: bash

  ./cuda_11.6.1_510.47.03_linux.run --silent --toolkit --installpath=/ceph-data4/fangjun/software/cuda-11.6.1 --no-opengl-libs --no-drm --no-man-page
  cd /ceph-data4/fangjun/software/cuda-11.6.1
  tar xvf /ceph-sh0/fangjun/cudnn/cudnn-11.3-linux-x64-v8.2.1.32.tgz --strip-components=1

CUDA 11.7.1
-----------

.. code-block:: bash

   wget https://developer.download.nvidia.com/compute/cuda/11.7.1/local_installers/cuda_11.7.1_515.65.01_linux.run
   chmod +x cuda_11.7.1_515.65.01_linux.run
   ./cuda_11.7.1_515.65.01_linux.run --silent --toolkit --installpath=/ceph-data4/fangjun/software/cuda-11.7.1 --no-opengl-libs --no-drm --no-man-page
   cd /ceph-data4/fangjun/software/cuda-11.7.1

