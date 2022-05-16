TypeMeta
========

See

  - `<https://github.com/pytorch/pytorch/blob/master/c10/util/typeid.h>`_
  - `<https://github.com/pytorch/pytorch/blob/master/c10/core/ScalarTypeToTypeMeta.h>`_

``struct TypeMeta`` contains only a single ``int16_t`` data member:

.. literalinclude:: ./code/type-meta/main.cc
   :language: c++
   :linenos:
   :lines: 3-5
   :caption: ./code/type-meta/main.cc (Check size)

Constructors
----------

.. literalinclude:: ./code/type-meta/main.cc
   :language: c++
   :linenos:
   :lines: 7-17
   :caption: ./code/type-meta/main.cc (Make)

Operations with ScalarType
--------------------------

.. literalinclude:: ./code/type-meta/main.cc
   :language: c++
   :linenos:
   :lines: 19-29
   :caption: ./code/type-meta/main.cc (Operations with ScalarType)
