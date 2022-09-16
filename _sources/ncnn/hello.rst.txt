Hello
=====

.. code-block:: bash

   git clone https://github.com/tencent/ncnn
   cd ncnn
   git checkout 7b4e77671a4457a414b60cee5425758212e725cf
   mkdir build
   cd build
   cmake -DCMAKE_PREFIX_PATH=/ceph-fj/fangjun/software/protobuf-3.20.1-cmake ..

We have to make the following changes:

.. literalinclude:: ./code/hello/7b4e77.diff
   :linenos:
   :caption: ./code/hello/7b4e77.diff


To install the Python package:

.. code-block:: bash

   cd ncnn
   mkdir build
   cd build
   cmake ..
   make -j
   cd ..
   pip install .

