argv
====

From the doc `<https://docs.python.org/3/library/sys.html>`_:

.. code-block::

  The list of command line arguments passed to a Python script.
  argv[0] is the script name (it is operating system dependent whether
  this is a full pathname or not). If the command was executed using the
  -c command line option to the interpreter, argv[0] is set to the string
  '-c'. If no script name was passed to the Python interpreter,
  argv[0] is the empty string.

Note that ``argv`` is at least of size 1, though ``argv[0]`` may be an
empty string.

.. code-block::

  import sys
  print(sys.argv)


