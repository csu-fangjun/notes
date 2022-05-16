.. _Load in CPP:

Load in C++
===========

Load the saved ``foo.pt`` in C++  from :ref:`export and ignore methods`.

.. literalinclude:: ./code/load-in-cpp/Makefile
   :language: makefile
   :linenos:
   :caption: ./code/load-in-cpp/Makefile

.. literalinclude:: ./code/load-in-cpp/main.cc
   :language: cpp
   :linenos:
   :caption: ./code/load-in-cpp/main.cc

The output of ``make`` is:

.. code-block::

  USE_CXX11_ABI 0
  TORCH_INSTALL_DIR /ceph-fj/fangjun/software/py38/lib/python3.8/site-packages/torch
  has cuda yes
  g++ -I/ceph-fj/fangjun/software/py38/lib/python3.8/site-packages/torch/include \
      -I/ceph-fj/fangjun/software/py38/lib/python3.8/site-packages/torch/include/torch/csrc/api/include \
      -I/ceph-fj/fangjun/software/py38/lib/python3.8/site-packages/torch/include/TH \
      -I/ceph-fj/fangjun/software/py38/lib/python3.8/site-packages/torch/include/THC \
      -std=c++14 \
      -D_GLIBCXX_USE_CXX11_ABI=0 \
      -Wno-unknown-pragmas \
      -I/ceph-sh1/fangjun/software/cuda-10.2.89/include \
      -c -o main.o main.cc
  g++ -o main main.o \
      -L/ceph-fj/fangjun/software/py38/lib/python3.8/site-packages/torch/lib \
      -lc10 -ltorch -ltorch_cpu \
      -Wl,-rpath,/ceph-fj/fangjun/software/py38/lib/python3.8/site-packages/torch/lib \
      -L/ceph-sh1/fangjun/software/cuda-10.2.89/lib64 \
      -lcudart -lc10_cuda -ltorch_cuda \
      -Wl,-rpath,/ceph-sh1/fangjun/software/cuda-10.2.89/lib64

The output of ``./main`` is:

.. code-block::

  is training: 1
  after m.eval(): is training: 0
   5
   6
   7
  [ CPUFloatType{3} ]
