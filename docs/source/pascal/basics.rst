Basics
======

system
------

- ``Chr(b)``, where b is a byte, it returns an ascii character

  See `<https://www.freepascal.org/docs-html/rtl/system/chr.html>`_

- ``Ord()``, see `<https://www.freepascal.org/docs-html/rtl/system/ord.html>`_

sysutils
--------

- ``IntToStr(i)`` to convert an integer to a string

  See `<https://www.freepascal.org/docs-html/rtl/sysutils/inttostr.html>`_

- ``StrToInt(s)`` to convert a string to an integer

  See `<https://www.freepascal.org/docs-html/rtl/sysutils/strtoint.html>`_.
  If the conversion failed, the above link gives an example about how to catch the exception.

  See also `StrToInDef <https://www.freepascal.org/docs-html/rtl/sysutils/strtointdef.html>`_,
  which returns a specified default value on conversion failure.

- ``Format()``, similar to ``sprintf()`` in C/C++.

  See `<https://www.freepascal.org/docs-html/rtl/sysutils/format.html>`_


Commonly used controls
-----------------------

.. code-block::

   Label.Caption := "hello"
