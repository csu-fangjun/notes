Integers
========

Like C++, it uses UTF-8 encoding for strings in Go.

.. literalinclude:: ./code/integers/main.go
   :caption: ./code/integers/main.go
   :language: go

Two kinds of for loops for ``strings``:

  - iterating it byte by byte
  - use for-range loop to iterate utf-8 encoded character by character
