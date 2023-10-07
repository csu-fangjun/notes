Install GCC
===========

.. code-block:: bash

   tar xvf gcc-12.2.0.tar.gz
   cd gcc-12.2.0
   mkdir build
   cd build

   unset C_INCLUDE_PATH
   unset CPLUS_INCLUDE_PATH
   unset LD_LIBRARY_PATH
   unset LIBRARY_PATH

   ../configure --prefix=/ceph-fj/fangjun/software/gcc-12.2.0
   make -j 5
   make install

.. code-block:: bash

   gcc_dir=/ceph-fj/fangjun/software/gcc-12.2.0
   export PATH=$gcc_dir/bin:$PATH
   export CC=$gcc_dir/bin/gcc
   export CXX=$gcc_dir/bin/g++
   export LIBRARY_PATH=$gcc_dir/lib64:$LIBRARY_PATH
   export LD_LIBRARY_PATH=$gcc_dir/lib64:$LD_LIBRARY_PATH
   export C_INCLUDE_PATH=$gcc_dir/include
   export CPLUS_INCLUDE_PATH=$gcc_dir/include

Using conda
-----------

.. code-block:: bash

   conda install -c conda-forge gcc==9.5.0
   conda install -c conda-forge gxx==9.5.0
