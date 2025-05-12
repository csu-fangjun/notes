sequence
========

- mutable sequences:
- immutable sequences:


`PySequence_Check <https://github.com/python/cpython/blob/main/Objects/abstract.c#L1672>`_

.. code-block:: python3

  int
  PySequence_Check(PyObject *s)
  {
      if (PyDict_Check(s))
          return 0;
      return Py_TYPE(s)->tp_as_sequence &&
          Py_TYPE(s)->tp_as_sequence->sq_item != NULL;
  }

We can see that if it is not a dict and if it has a method ``__getitem__``, then it returns 1.
