ScalarType
==========

See `c10/core/ScalarType.h <https://github.com/pytorch/pytorch/blob/master/c10/core/ScalarType.h>`_.
and
`<https://github.com/pytorch/pytorch/blob/master/torch/csrc/api/include/torch/types.h>`_.

``ScalarType`` is an ``enum class``, i.e., ``enum class ScalarType : int8_t { ... }``.

Members
-------

It has the following members:

.. literalinclude:: ./code/scalar-type/members.cc
   :language: c++
   :linenos:
   :caption: ./code/scalar-type/members.cc

Some aliases
^^^^^^^^^^^^

.. literalinclude:: ./code/scalar-type/main.cc
   :language: c++
   :linenos:
   :lines: 18-21
   :caption: ./code/scalar-type/main.cc (alias)

.. literalinclude:: ./code/scalar-type/alias.cc
   :language: c++
   :linenos:
   :caption: ./code/scalar-type/alias.cc

ScalarType to CPP type
----------------------


.. literalinclude:: ./code/scalar-type/main.cc
   :language: c++
   :linenos:
   :lines: 5-11
   :caption: ./code/scalar-type/main.cc

CPP type to ScalarType
----------------------

.. literalinclude:: ./code/scalar-type/main.cc
   :language: c++
   :linenos:
   :lines: 13-17
   :caption: ./code/scalar-type/main.cc

.. note::

   It is ``c10::impl::ScalarTypeToCPPType``, but it is ``c10::CppTypeToScalarType``.
