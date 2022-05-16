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

