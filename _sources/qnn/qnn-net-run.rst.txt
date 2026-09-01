qnn-net-run
===========

help
----

.. code-block::

   qnn-net-run --help

.. literalinclude:: ./code/qnn-net-run.txt

On Android
----------

1. Copy ``/star-fj/fangjun/download/qnn/qairt/2.32.0.250228/bin/aarch64-android/qnn-net-run`` to android

.. code-block::

  adb push ./qnn-net-run /data/local/tmp/

Then ``adb shell`` and switch to ``/data/local/tmp`` and run ``chmod +x ./qnn-net-run``

2. Copy the following files from ``/star-fj/fangjun/download/qnn/qairt/2.32.0.250228/lib/aarch64-android/`` to androido

  - ``libQnnGpu.so``
  - ``libQnnHtp.so``
