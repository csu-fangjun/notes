Basics
======

Extract part of a wave
----------------------

.. code-block::

  # offset 2 seconds, length 0.195 seconds
  sox in.mp3 out.mp3 trim 2 0.195


Fix broken waves
----------------

.. code-block:: bash

   sox --ignore-length corrupted.wav fixed.wav

pad
---

.. code-block:: bash

   # add 2 seconds of silence at the begining and 3 seconds of silence
   # at the end.
   sox in.wav out.wav pad 2 3
