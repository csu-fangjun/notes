ffmeg
=====


.. code-block::

   ffprobe xxx.opus

Convert format
--------------

- opus to wav

.. code-block:: bash

   ffmpeg -i input.opus output.wav

   ffmpeg -i input.opus -acodec pcm_s16le -ac 1 -ar 16000 output.wav

- Extract part of a file

.. code-block:: bash

   # extract 30 seconds starting at offset 1 minute
   ffmpeg -i input.opus -ss 60 -t 30 output.wav
   # or use HH:MM:SS format
   ffmpeg -i input.opus -ss 0:01:00 -t 0:00:30 output.wav

   ffmpeg -ss 00:00:16 -to 00:00:30 -i ./abc.mov -c copy part.mp4


References
----------

See `<https://gist.github.com/whizkydee/804d7e290f46c73f55a84db8a8936d74>`_
