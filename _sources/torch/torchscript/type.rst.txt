type
====

See:
- `<https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/core/jit_type_base.h>`_
- `<https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/core/jit_type.h>`_
- `<https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/core/type_ptr.h>`_

``torch::Type`` contains a member ``torch::TypeKind``.
``torch::SharedType`` is a subclass of ``torch::Type`` and ``std::enabled_shared_from_this<torch::SharedType>``.

.. code-block:: cpp

  // https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/core/jit_type_base.h#L637
  using TypePtr = SingletonOrSharedTypePtr<Type>;


.. literalinclude:: ./code/type/main.cc
   :language: cpp
   :linenos:
   :caption: ./code/type/main.cc
