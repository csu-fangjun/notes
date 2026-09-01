Install
=======

See `<https://grpc.io/docs/languages/cpp/quickstart/>`_

.. code-block:: bash

   git clone --recurse-submodules -b v1.46.3 --depth 1 --shallow-submodules https://github.com/grpc/grpc
   mkdir build
   cd build
   cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=/ceph-fj/fangjun/software/grpc-1.46.3 .. 2>&1 | tee cmake-configure-1.log
   make -j20 2>&1 | tee make-1.log
   make install 2>&1 | tee make-2.log
