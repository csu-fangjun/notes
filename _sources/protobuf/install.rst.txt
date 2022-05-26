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
