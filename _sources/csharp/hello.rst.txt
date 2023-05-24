Hello
=====

.. code-block:: bash

   dotnet new console -h Hello

unsafe
------

.. literalinclude:: ./code/Hello/UnsafeTest.cs

References:

-  `Unmanaged types (C# reference) <https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/unmanaged-types>`_
- `fixed statement - pin a variable for pointer operations <https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/statements/fixed>`_
- `stackalloc <https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/operators/stackalloc>`_
- `Pointer related operators - take the address of variables, dereference storage locations, and access memory locations <https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/operators/pointer-related-operators>`_
- `Unsafe code, pointer types, and function pointers <https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/unsafe-code>`_
- `23 Unsafe code <https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/language-specification/unsafe-code>`_
- `Dos and Don'ts of stackalloc <https://vcsjones.dev/stackalloc/>`_

Span
----

.. literalinclude:: ./code/Hello/SpanTest.cs

References:

-

File
----

.. literalinclude:: ../code/Hello/FileTest.cs


TODO
----

- stackalloc
- unsafe code
- unit test
- Marshal, read/write memory
- MemoryStream, FileStream
- FileReader, BinaryWriter
- directory exists, file exists
