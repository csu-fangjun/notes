How to include code from a file
===============================

See `<https://www.sphinx-doc.org/en/master/usage/restructuredtext/directives.html#directive-literalinclude>`_.

1. Show line number: ``:linenos:``. By default, line number counts from 0.
   To add an offset, e.g., 10, to the line number, use ``:lineno-start: 10``.
   Note: It still includes all the contents of the file.

2. To emphasize a line, specified lines, or specified line ranges, use:
   ``:emphasize-lines: 10``, ``:emphasize-lines: 10,12,14``, and ``:emphasize-lines: 12,15-18``
   Note: emphasize means to change the background color.

3. Set the language, e.g., ``:language: python``.

4. Set the caption, e.g., ``:caption: hello world``.

5. To include a function from the python file, use ``:pyobject: my_func``

6. To include specified lines, use ``:lines:1,3,5-10,15-``. Note that if using this option,
   line number counts from 0. Use ``:lineno-start: xx`` to change the offset for display.
