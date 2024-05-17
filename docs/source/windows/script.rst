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

Change default shell to powershell for OpenSSH
----------------------------------------------

See `<https://superuser.com/questions/1799896/how-to-configure-powershell-for-openssh-instead-of-cmd>`_

.. code-block::bash

  New-ItemProperty -Path "HKLM:\SOFTWARE\OpenSSH" `
                   -Name DefaultShell `
                   -Value "C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe" `
                   -PropertyType String `
                   -Force
