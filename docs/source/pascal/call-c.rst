Call C
======

- 7.1 Using external code and variables

  `<https://www.freepascal.org/docs-html/prog/progse28.html>`_

  The official fpc documentation for calling external functions and variables.

- Using C object files in Delphi

  `<http://rvelthuis.de/articles/articles-cobjs.html>`_

- How to use C code in Free Pascal projects

  `<https://downloads.freepascal.org/fpc/docs-pdf/CinFreePascal-old.pdf>`_

- Creating Pascal bindings for C

  `<https://github.com/csukuangfj/pascal-bindings-for-c/blob/master/docs/Creating%20Pascal%20bindings%20for%20C%20(v1.0).pdf>`_

  It shows how to use ``xxx.o``, ``libxxx.a`` and ``libxxx.so`` in free pascal
  It also contains source files hosted on GitHub.

- `<https://github.com/PascalGameDevelopment/SDL2-for-Pascal/blob/master/units/sdl2.pas>`_

  Read it carefully. It has lots of examples!

- See also `<https://github.com/MagicFoundation/Alcinoe/blob/master/Source/ZLibEx.pas>`_

- `<https://github.com/gidesa/ocvWrapper24/blob/main/Delphi/OPENCVWrapper.pas>`_

  OpenCV wrapper for delphi

- `<https://github.com/Kagamma/whisper-pas/blob/master/src/whisper.pas>`_

  Wrapper for whisper

- Manual conversion of C headers to Pascal

  `<https://wiki.lazarus.freepascal.org/Creating_bindings_for_C_libraries#Manual_conversion_of_C_headers_to_Pascal>`_

- See the following link for how to wrap ``printf``, which accepts unconstrained number of arguments

  `<https://www.freepascal.org/docs-html/prog/progsu149.html>`_

  Note that it proposes two methods.

ctypes
------

``ctypes.inc`` can be found at `<https://github.com/fpc/FPCSource/blob/main/rtl/unix/ctypes.inc>`_.

It defines commonly used integer types for C/C++.

  - cint32, pcint32
  - cfloat, pcfloat
  - cdouble, pcdouble
  - csize_t, pcsize_t

linklib
-------

To link a lib in the code::

  {$L xxx}
  // or
  {$LinkLib xxx}

  // Note xxx can be on object file, e..g, use {$L foo.o}
  // or it can be a library {$L foo} to link with libfoo.so, libfoo.dylib

  // On windows, we have to use {$L foo.dll}
  // See https://www.freepascal.org/docs-html/prog/progsu149.html

Or at the commandlin use ``-Flxxx``

To specify the object file in the commandline, use ``-Fo``

Example 1 on macOS
-------------------

See also `<https://www.freepascal.org/docs-html/prog/progsu147.html>`_

Things to take away:

  1. We can link an object file in pascal
  2. The c variable name is mangled by adding a leading `_` by the compiler.
  3. If we use ``cvar`` without a ``name`` after external, then the fpc compiler
     handles the name mangling by ourselves.
  4. If we don't use cvar and instead use a ``name``, then we must
     add a leading ``_``.
  5. If we don't use ``cvar`` and don't use ``name``, then the variable
     must be named as the mangled c variable name.


``extvar.c`` is given below::

  /*
  Declare a variable, allocate storage
  */
  int extvar = 12;

``extdemo.pas`` is given below:

.. code-block:: pascal

  Program ExtDemo;

  {$L extvar.o}
  // {$LinkLib extvar.o} // either one is ok
  // By default, it tries to find extvar.o in the current directory.
  // If it is not found, then an error is throw.
  //
  // To fix it, we can use -Fl/some/path
  // where we extvar.o is inside /some/path

  var
    { Case sensitive declaration }
    extvar : longint; cvar; external;
    _extvar : longint; external;
    I : longint; external name '_extvar';

  begin
    { Extvar can be used case insensitively }
    Writeln ('Variable ''extvar'' has value: ',ExtVar);
    Writeln ('Variable ''_extvar'' has value: ',_ExtVar);
    Writeln ('Variable ''I''      has value: ',i);
    I := 13;
    Writeln ('Variable ''extvar'' has value: ',ExtVar);
    Writeln ('Variable ''_extvar'' has value: ',_ExtVar);
    Writeln ('Variable ''I''      has value: ',i);
  end.


Build command::

  gcc -c -o extvar.o extvar.c
  fpc ./extdemo.pas

Output log is::

  Free Pascal Compiler version 3.2.2 [2021/05/16] for x86_64
  Copyright (c) 1993-2021 by Florian Klaempfl and others
  Target OS: Darwin for x86_64
  Compiling ./extdemo.pas
  Assembling extdemo
  Linking extdemo
  ld: warning: object file (extvar.o) was built for newer macOS version (13.0) than being linked (10.8)
  17 lines compiled, 0.6 sec

The command::

  nm ./extvar.o

prints::

  0000000000000000 D _extvar

And::

 ./extdemo

prints::

  Variable 'extvar' has value: 12
  Variable '_extvar' has value: 12
  Variable 'I'      has value: 12
  Variable 'extvar' has value: 13
  Variable '_extvar' has value: 13
  Variable 'I'      has value: 13
