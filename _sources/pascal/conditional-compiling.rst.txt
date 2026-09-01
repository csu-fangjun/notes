Conditional compiling
=====================

predefined symbols
------------------

Please see `<https://www.freepascal.org/docs-html/3.0.0/prog/progap7.html#x333-348000G>`_.

``unix`` is defined for both macos and unbuntu.

``darwin`` is defined only for macos.

``windows`` is for both 32-bit and 64-bit windows.

user defined symbols
--------------------

To pass from the commandline::

  fpc -dmy_symbol

that is, use ``-d`` option. It is equivalent to::

  {$define my_symbol}

in the code.

To un-define a symbol from the commandline::

  fpc -umy_symbol

That is, use ``-u`` option. It is equivalent to::

  {#undef my_symbol}

in the code.

if and else
-----------

There are multiple forms:

**Example 1**

.. code-block:: pascal

   {$ifdef my_symbol}
     {some code}
   {$endif}

   {$ifdef my_symbol with some comments}
     {some code}
     {everything after my_symbol is a comment}
   {$endif}

   {$ifdef my_symbol}
     {some code}
   {$else}
     {some other code}
   {$endif}

   {$ifdef my_symbol}
     {some code}
   {$elseif defined(foo)}
     {some code}
   {$endif}

   {$if defined(foo) or defined(bar)}
   {$endif}

   {$if defined(foo) and defined(bar)}
   {$endif}


   {$if defined(my_symbol)}
     {some code}
   {$elseif defined(foo)}
     {some code}
   {$endif}

   {$if defined(my_symbol)}
     {some code}
   {$elseif defined(foo) or defined(bar) or defined(foobar)}
     {some code}
   {$endif}

**Example2**

.. code-block::

   {$ifndef foo}
     {code}
   {$endif}

   {$if not defined(foo)}
     {code}
   {$endif}

To summarize, we can use

  - ``ifdef``, ``endif``
  - ``ifndef``
  - ``else``, ``elseif``
  - ``if`` (we can use conditions, e.g., ``if defined() or defined()``
  - ``defined``
  - ``undef``

Some more examples from `<https://github.com/fpc/FPCSource/blob/main/rtl/unix/dl.pp>`_

.. code-block:: bash

  {$if defined(linux) or defined(freebsd) or defined(openbsd) or defined(dragonfly)}
    {$define ELF} // ELF symbol versioning.
  {$endif}

  {$if defined(linux)}
      { if libc is not linked explicitly, FPC might chose the wrong startup code, as
        libdl depends on libc on linux, this does not hurt }
      {$linklib c}
  {$endif}

  function dladdr(Lib: pointer; info: Pdl_info): Longint; cdecl; {$if not defined(aix) and not defined(android)} external; {$endif}

  const
  {$ifdef BSD}   // dlopen is in libc on FreeBSD.
    LibDL = 'c';
  {$else}
    {$ifdef HAIKU}
      LibDL = 'root';
    {$else}
      LibDL = 'dl';
    {$endif}
  {$endif}

Some more examples from `<https://github.com/fpc/FPCSource/blob/main/rtl/inc/ctypes.pp>`_

.. code-block::

  {$ifdef FPC}
    {$inline on}
    {$ifndef DISABLE_INLINE}
       {$define CTYPES_INLINE}
    {$endif}
    {$define dummy}
  {$endif}
