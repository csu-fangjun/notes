array
=====


An array is of fixed size and cannot be resized, like C/C++.

- ``len(a) ==cap(a)``, return the capcity of an array

.. literalinclude:: ./code/array/main.go
   :caption: ./code/array/main.go
   :language: go

slice
-----

Differences between::

  a := []int

and::

  b := []int{}
