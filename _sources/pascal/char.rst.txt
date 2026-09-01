char
====

A character ``char`` is 1 byte in pascal.

``AnsiChar`` is an alias to ``Char``. See `<https://www.freepascal.org/docs-html/rtl/system/ansichar.html>`_.

`'a'` is a ``char``. Note only single quote is used. Double quotes are not correct.

See `<https://wiki.freepascal.org/Character_and_string_types>`_ for different types of strings:

  - ``AnsiChar``
  - Static array of char
  - Dynamic array of char, see also `<https://www.freepascal.org/docs-html/rtl/system/setlength.html>`_
    We need to free the memory by passing 0 to ``SetLength``

.. code-block:: pascal

   var
     a: char;
   begin
     a := 'a';
     a := #65; // equivalent to a := 'a'

     a := ''''; // a is a single quote here.
   end.

There is also a ``string`` type, which can contain at most 255 characters.

.. code-block:: pascal

   var
     s: string;
     s2: string[255]; // both s ans s2 have 256 bytes.
    begin
      writeln ('SizeOf(s) is ', SizeOf(s)); // Sizeof(s) is 256
      writeln ('SizeOf(s2) is ', SizeOf(s2)); // Sizeof(s2) is 256
      s := 'hello';
      writeln('s[0] is ', ord(s[0])); // s[0] is 5
    end.

Note ``var s: string[size]`` will allocate ``size + 1`` bytes.
size can be any value from 1 to 255. ``s[0]`` contains the length of the string.
If ``[size]`` is not specified, then it is equivalent to ``[255]``.

``pchar``:

  - It is similar to the strings in C, which ends with `\0`. pchar is a pointer

  - See `<https://www.freepascal.org/docs-html/ref/refsu12.html>`_

  .. code-block::

    var
     p: pchar;
    begin
      p := 'hello world';
      writeln ('p is ', p); // p is hello world
    end.

  Example 2::

    var
     s: string;
     p: pchar;
    begin
      s := 'hello world'#0; // Use #0 to append a \0 at the end
      p := @s[1]; // s[0] is the length of the string, so we use @s[1] here
      writeln ('p is ', p); // p is hello world
    end.

  - Use ``StrLen`` for ``pchar``, but use ``Length`` for ``string``.
