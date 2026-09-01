Pointers
========

See `<https://www.freepascal.org/docs-html/ref/refse15.html>`_

``null`` pointers in pascal is ``nil``.

See also `<https://en.wikibooks.org/wiki/Pascal_Programming/Pointers>`_

.. code-block:: pascal

   var
     p: ^integer;
     i: integer;
   begin
     i := 3;
     p := @i; // get the address of i
     p^ += 2; // equivalent to *p += 2 in c/c++
     Writeln('i is ', i); // is is 5
   end.


- The ``new`` function from `<https://www.freepascal.org/docs-html/3.2.0/rtl/system/new.html>`_

  It is declared as::

    procedure New(
      var P: Pointer
    );

  Note that the argument type is ``Pointer``, which is an untyped pointer.
  Also note the argument is ``var``, meaning it is an input/output argument

  Example::

    var
     p: ^integer;
    begin
      New(p); // allocate space and save the address to p
      p^ := 10;
      writeln ('p^ is ', p^); // p^ is 10
      Dispose(p); // free p
    end.

- ``GetMem()`` and ``FreeMem()``

  See `<https://www.freepascal.org/docs-html/3.2.0/rtl/system/freemem.html>`_

- ``FillByte()``, ``FillChar()``, ``FillWord()``, ``FillDWord()``, are similar to ``memset`` in C/C++.

  `<https://www.freepascal.org/docs-html/3.2.0/rtl/system/fillchar.html>`_
