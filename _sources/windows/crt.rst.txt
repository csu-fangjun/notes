CRT
===

See also
`<https://www.amd.com/en/developer/resources/technical-articles/2026/a-practical-approach-to-using-sherpa-onnx-production-ready-on-wi.html>`_

- `<https://learn.microsoft.com/en-us/cpp/build/reference/md-mt-ld-use-run-time-library?view=msvc-170>`_

 It describes ``MT``, ``MTd``, ``MD``, ``MDd``

 - C runtime (CRT) and C++ standard library (STL) .lib files

  `<https://learn.microsoft.com/en-us/cpp/c-runtime-library/crt-library-features?view=msvc-170>`_



.. code-block::

   dumpbin /directives lib\Release\sherpa-onnx-c-api.lib | findstr RuntimeLibrary

.. code-block::

   for %f in (*.lib) do @echo %f & dumpbin /directives "%f" | findstr RuntimeLibrary

