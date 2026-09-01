Basics
======

.. literalinclude:: ./code/hello.dart
   :language: dart
   :linenos:
   :caption: ./code/hello.dart

.. literalinclude:: ./code/hello2.dart
   :language: dart
   :linenos:
   :caption: ./code/hello2.dart

The entrypoint is the ``main`` function. It can take 0 argument or a list argument.

Note that ``print`` outputs a newline.

The help info for ``print`` can be found at
`<https://api.dart.dev/dart-core/print.html>`_. Note that its prototype is::

  void print(Object? object)

It can print any type!

.. literalinclude:: ./code/test-math.dart
   :language: dart
   :linenos:
   :caption: ./code/test-math.dart


Naming convention ``MyClass.myMethod()``, ``myVariable``, ``sourceUrl``,
``urlDestination``.

A string uses ``utf-16`` encoding, like JavaScript. We can use either a single quote or
double quotes for string literals, e.g., ``'hello'`` and ``"hello"`` are equal.

Type of a string is ``String``.

String interpolation is like javascript, e.g., ``"hello ${world}"``, ``"hello $world"``.
We can put arbitrary expression inside ``${}``.

Note that ``String`` is immutable in Dart, like Python.

Doc for functions `<https://dart.dev/language/functions>`_.

Doc for packages `<https://dart.dev/guides/packages>`_.

``num`` is a super class of ``int`` and ``double``.
``int`` is 64-bit.

There is also a ``bool`` type with ``true`` and ``false``.

``String`` and ``num`` are subtypes of ``Object``.
All non-nullable types in Dart are subtype of ``Object``.


Like kotlin, it has nullable types.

Collection type examples:

  - a list, ``List<int>``. See help at `<https://api.dart.dev/stable/3.4.0/dart-core/List-class.html>`_
  - a set, ``Set<String>``
  - a map, ``Map<String, int>``

Two ways to create a list::

  var s = <String>[];
  List<String> s = [];


.. code-block:: dart

   int? a; // default initialized to null

   a ??= 3; // assign 3 to a if a is not null; else do nothing.

   a = null;

   int b = a ?? 10; // if a is not null, assign a to b, else assign 10 to b


.. literalinclude:: ./code/test1.dart
   :language: dart
   :linenos:
   :caption: ./code/test1.dart


.. literalinclude:: ./code/test2.dart
   :language: dart
   :linenos:
   :caption: ./code/test2.dart

control
----------

.. literalinclude:: ./code/test-control.dart
   :language: dart
   :linenos:
   :caption: ./code/test-control.dart

record
-------

.. literalinclude:: ./code/test_record.dart
   :language: dart
   :linenos:
   :caption: ./code/test_record.dart

function
--------

.. literalinclude:: ./code/test-function.dart
   :language: dart
   :linenos:
   :caption: ./code/test-function.dart

class
-----

.. literalinclude:: ./code/test-class.dart
   :language: dart
   :linenos:
   :caption: ./code/test-class.dart

null
-----

.. literalinclude:: ./code/test-null.dart
   :language: dart
   :linenos:
   :caption: ./code/test-null.dart

list
-----

.. literalinclude:: ./code/test-list.dart
   :language: dart
   :linenos:
   :caption: ./code/test-list.dart

set
-----

.. literalinclude:: ./code/test-set.dart
   :language: dart
   :linenos:
   :caption: ./code/test-set.dart

map
-----

.. literalinclude:: ./code/test-map.dart
   :language: dart
   :linenos:
   :caption: ./code/test-map.dart

string
-----

.. literalinclude:: ./code/test-string.dart
   :language: dart
   :linenos:
   :caption: ./code/test-string.dart

events
-------

.. literalinclude:: ./code/test-events.dart
   :language: dart
   :linenos:
   :caption: ./code/test-events.dart

isolate
-------

.. literalinclude:: ./code/test-isolate.dart
   :language: dart
   :linenos:
   :caption: ./code/test-isolate.dart
