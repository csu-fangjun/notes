.. _install protobuf:

Installation
============

C++
---

See `<https://github.com/protocolbuffers/protobuf/blob/main/src/README.md>`_.

.. code-block::

   make protocol-buffers
   cd protocol-buffers
   wget https://github.com/protocolbuffers/protobuf/releases/download/v3.20.1/protobuf-all-3.20.1.tar.gz
   tar xvf protobuf-all-3.20.1.tar.gz
   cd protobuf-all-3.20.1
   ./configure --prefix=$HOME/software/protobuf-3.20.1
   make -j 20
   make -j 10 check
   make install 2>&1 | tee my-log.txt
   cd $HOME/software/protobuf-3.20.1
   tree . > tree-log.txt

.. code-block:: bash

  $ export PKG_CONFIG_PATH=$HOME/software/protobuf-3.20.1:$PKG_CONFIG_PATH

  $ pkg-config --cflags protobuf
  -I/root/fangjun/software/protobuf-3.20.1/include

  $ pkg-config --libs protobuf
  -L/root/fangjun/software/protobuf-3.20.1/lib -lprotobuf

  $ pkg-config --cflags --libs  protobuf
  -I/root/fangjun/software/protobuf-3.20.1/include -L/root/fangjun/software/protobuf-3.20.1/lib -lprotobuf

  $ pkg-config --libs-only-L  protobuf
  -L/root/fangjun/software/protobuf-3.20.1/lib

  $ pkg-config --libs-only-l  protobuf
  -lprotobuf

.. code-block:: bash

   $ export PATH=$HOME/software/protobuf-3.20.1/bin:$PATH
   $ protoc --version
   libprotoc 3.20.1



.. literalinclude:: ./code/my-log.txt
   :linenos:
   :caption: ./code/my-log.txt (Installation logs)

.. literalinclude:: ./code/tree-log.txt
   :linenos:
   :caption: ./code/tree-log.txt (Installed files)

Install with cmake
------------------


.. code-block::

   make protocol-buffers
   cd protocol-buffers
   wget https://github.com/protocolbuffers/protobuf/releases/download/v3.20.1/protobuf-all-3.20.1.tar.gz
   tar xvf protobuf-all-3.20.1.tar.gz
   cd protobuf-all-3.20.1
   mkdir my-build
   cd my-build
   cmake -Dprotobuf_BUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=/ceph-fj/fangjun/software/protobuf-3.20.1-cmake/ ../cmake 2>&1 | tee cmake-configure-shared-lib.log
   make -j10 2>&1 | tee make-shared.log
   make install 2>&1 | tee make-shared-install.log

   cd $HOME/software/protobuf-3.20.1-cmake
   tree . > tree-cmake-log.txt


..
  .. literalinclude:: ./code/cmake-configure-shared-lib.log
     :linenos:
     :caption: ./code/cmake-configure-shared-lib.log

  .. literalinclude:: ./code/make-shared.log
     :linenos:
     :caption: ./code/make-shared.log

  .. literalinclude:: ./code/make-shared-install.log
     :linenos:
     :caption: ./code/make-shared-install.log

  .. literalinclude:: ./code/tree-cmake-log.txt
     :linenos:
     :caption: ./code/tree-cmake-log.txt
