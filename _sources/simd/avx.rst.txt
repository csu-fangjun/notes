avx
===

SSE4 data types:

  - ``__m128``, 4 floats
  - ``__m128d``, 2 doubles
  - ``__m128i``, it depends, can be 16 8-bit, 8 16-bit, 4 32-bit, 2 64-bit

AVX2 data types:

  - ``__m256``, 8 floats
  - ``__m256d``, 4 doubles
  - ``__m256i``, 32 8-bt, 16 16-bit, 8 32-bit, 4 64-bit

.. literalinclude:: ./code/avx/main.cc
   :language: c++
   :linenos:
   :caption: ./code/avx/main.cc
