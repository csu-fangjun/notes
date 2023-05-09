Call cpp
========

1. Start xcode
2. Create a new project, macOS -> Command Line Tool
3. Product name: TestCpp
4. Language Swift
5. Edit ``main.swift``, keep only ``println("hello world")`` and remove other lines
6. Product -> Run
7. Create a c++ shared library

.. literalinclude:: ./code/call_cpp/hello.h
   :language: c++
   :caption: ./code/call_cpp/hello.h

.. literalinclude:: ./code/call_cpp/hello.cc
   :language: c++
   :caption: ./code/call_cpp/hello.cc

.. literalinclude:: ./code/call_cpp/Makefile
   :language: c++
   :caption: ./code/call_cpp/Makefile

8. In xcode, project->build phases->frameworks and libraries, click ``+``, and select
   ``libhello.a``. Then, modify build settings to change the library search paths (in search paths)
9. Add ``hello.h`` to the same folder of ``main.swfit``. File->Add files to ``TestCpp``.
10. Add a wrapper. File->New->File->C++ file, next, choose an arbitrary name, e.g., ``wrapper.cc``.
    Uncheck ``Also create a header file``. We only need the ``.cc`` file.
    In the popped-up dialog, select ``Create bridging header``.
11. If we don't select ``Create bridging header``, we have to go to build settings,
    swift compiler, objective-c bridging header, and enter a header name.
12. Content of ``wrapper.cc``

.. code-block:: c++

  #include "hello.h"
  extern "C" int getIntFromCpp() {
      return A(10).getInt();
  }

13. Content of the bridging header ``TestCpp-Briding-Header.h``:

.. code-block:: c++

  int getIntFromCpp();

14. In ``main.swift``, use ``print(getIntFromCpp())``

