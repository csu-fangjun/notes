ArrayRef
========

See ``c10/utils/ArrayRef.h``.

.. caution::

   ``IntArrayRef`` is an alias to ``ArrayRef<int64_t>``.


``ArrayRef<T>`` contains only two members: A const data pointer and a size.
It is trivially copyable and assignable.

It has similar methods like ``std::vector``. It also has two methods to
get the front and back: ``front()`` and ``back()``; both return a const reference.

Its method ``vec()`` converts itself to a ``std::vector`` by **copying** the underlying data.

Constructors
------------

Data members
^^^^^^^^^^^^

.. literalinclude:: ./code/array_ref/main.cc
   :language: c++
   :linenos:
   :lines: 3-11
   :emphasize-lines: 2-3,8
   :caption: ./code/array_ref/main.cc (Check size)

Default constructed
^^^^^^^^^^^^^^^^^^^

.. literalinclude:: ./code/array_ref/main.cc
   :language: c++
   :linenos:
   :lines: 13-21
   :caption: ./code/array_ref/main.cc (Default constructor)

From a single element
^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: ./code/array_ref/main.cc
   :language: c++
   :linenos:
   :lines: 23-29
   :caption: ./code/array_ref/main.cc (From a single element)

From an initializer list
^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: ./code/array_ref/main.cc
   :language: c++
   :linenos:
   :lines: 31-37
   :caption: ./code/array_ref/main.cc (From an initializer list)

Other types of constructors
^^^^^^^^^^^^^^^^^^^^^^^^^^^

  - From two pointers: begin and end
  - From a pointer and a length
  - From a `std::vector`
  - From a container that has ``data()`` and ``size()`` methods
  - From a C array
  - From a ``std::array``
