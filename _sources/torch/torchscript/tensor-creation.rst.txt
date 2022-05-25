Tensor Creation
===============

See


TensorDataContainer
-------------------

.. note::

   data is **copied** to the returned tensor!


See

  - `<https://github.com/pytorch/pytorch/blob/master/torch/csrc/api/include/torch/detail/TensorDataContainer.h>`_
  - `<https://github.com/pytorch/pytorch/blob/master/tools/autograd/templates/variable_factories.h>`_
  - `<https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/Utils.cpp>`_

Support the following data types:

  - From a ``std::vector<T>``
  - From a scalar
  - From an initializer list
  - From an ``ArrayRef<T>``.

From std::vector
----------------

.. literalinclude:: ./code/tensor-creation/main.cc
   :language: c++
   :linenos:
   :lines: 3-23
   :caption: ./code/tensor-creation/main.cc

From scalar
-----------

.. literalinclude:: ./code/tensor-creation/main.cc
   :language: c++
   :linenos:
   :lines: 25-31
   :caption: ./code/tensor-creation/main.cc

From initializer list
---------------------

.. literalinclude:: ./code/tensor-creation/main.cc
   :language: c++
   :linenos:
   :lines: 33-45
   :caption: ./code/tensor-creation/main.cc

From ArrayRef
-------------

.. literalinclude:: ./code/tensor-creation/main.cc
   :language: c++
   :linenos:
   :lines: 47-56
   :caption: ./code/tensor-creation/main.cc
