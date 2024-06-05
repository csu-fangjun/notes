macos
=====

Copy content to the clipboard:

.. code-block:: bash

   cat result.txt | pbcopy

Port scan
---------

.. code-block:: bash

   brew install masscan
   sudo masscan -p 1-10000 137.184.92.35

Update GCC
----------

.. code-block:: bash

    brew upgrade gcc

    export CC=/usr/local/Cellar/gcc/13.1.0/bin/gcc-13
    export CXX=/usr/local/Cellar/gcc/13.1.0/bin/g++-13
    export CMAKE_C_COMPILER=$CC
    export CMAKE_CXX_COMPILER=$CXX
