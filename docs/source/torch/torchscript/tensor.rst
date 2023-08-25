Tensor
======

See

  - `<https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/core/TensorBase.h>`_
  - `<https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/templates/TensorBody.h>`_
  - `<https://github.com/pytorch/pytorch/blob/master/c10/core/TensorImpl.h>`_

Common methods
--------------

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 3-84
   :caption: ./code/tensor/main.cc (Not recommended constructors)

slice
^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 86-99
   :caption: torch::slice

topk
^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 101-116
   :caption: torch::topk

floor_divide
^^^^^^^^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 118-127
   :caption: torch::floor_divide

div
^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 129-140
   :caption: torch::div

remainder
^^^^^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 143-150
   :caption: torch::remainder

empty
^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 152-156
   :caption: torch::empty

stack
^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 158-168
   :caption: torch::stack

unbind
^^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 170-177
   :caption: torch::unbind

full
^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 179-185
   :caption: torch::full

split
^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 187-199
   :caption: torch::split

zeros
^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 201-203
   :caption: torch::zeros

cat
^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 206-211
   :caption: torch::cat

division
^^^^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 213-231
   :caption: test division

default constructed
^^^^^^^^^^^^^^^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 233-235
   :caption: test default constructed

copy
^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 238-248
   :caption: test rowwise copy

default addmm
^^^^^^^^^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 250-264
   :caption: test default constructed

elementwise operation
^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 266-277
   :caption: test elementwise operation

torch.roll
^^^^^^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 279-306
   :caption: torch.roll

torch.mean
^^^^^^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 208-321
   :caption: torch.mean

torch.index
^^^^^^^^^^^

.. literalinclude:: ./code/tensor/main.cc
   :language: c++
   :linenos:
   :lines: 323-330
   :caption: torch.mean
