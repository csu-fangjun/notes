Scripts
=======

Activate Visual studio
----------------------

.. code-block:: bash

   "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

View DLL dependencies
---------------------

.. code-block:: bash

  dumpbin  /dependents .\onnxruntime_providers_cuda.dll

Remove folder
-------------

.. code-block:: bash

   del /s /q .\*
