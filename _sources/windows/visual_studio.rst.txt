Visual studio
=============


Activate it in the command line:

.. code-block:: bash

   "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"

Property files
--------------

- Managing dependencies in Visual Studio C++ projects with property files

  `<https://blog.conan.io/2021/02/10/Dependencies-Visual-Studio-C++-property-files.html>`_

- .vcxproj and .props file structure

  `<https://learn.microsoft.com/en-us/cpp/build/reference/vcxproj-file-structure?view=msvc-160>`_

View symbols:

.. code-block:: bash

   dumpbin -linkermember .\xxx.lib
