Basics
======

See

- A Swift Tour

  `<https://docs.swift.org/swift-book/GuidedTour/GuidedTour.html#//apple_ref/doc/uid/TP40014097-CH2-ID1>`_

- Getting Started

  `<https://www.swift.org/getting-started>`_

.. code-block:: bash

  swift --version
  swift-driver version: 1.62.15 Apple Swift version 5.7.2 (swiftlang-5.7.2.135.5 clang-1400.0.29.51)
  Target: x86_64-apple-macosx13.0


To start the REPL commandline:

.. code-block:: bash

  swift repl

.. literalinclude:: ./code/1-hello.swift
   :language: swift
   :caption: ./code/1-hello.swift

.. code-block:: bash

  swiftc ./1-hello.swift

It will generate an executable ``./1-hello``.

.. code-block::

  otool -L ./1-hello

  ./1-hello:
    /usr/lib/libobjc.A.dylib (compatibility version 1.0.0, current version 228.0.0)
    /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1319.0.0)
    /usr/lib/swift/libswiftCore.dylib (compatibility version 1.0.0, current version 5.7.1)

  ls -lh 1-hello

  -rwxr-xr-x  1 fangjun  staff    33K Jan 21 11:55 1-hello

.. literalinclude:: ./code/2-variables.swift
   :language: swift
   :caption: ./code/2-variables.swift

.. literalinclude:: ./code/3-array-dict.swift
   :language: swift
   :caption: ./code/3-array-dict.swift

.. literalinclude:: ./code/4-if.swift
   :language: swift
   :caption: ./code/4-if.swift

.. literalinclude:: ./code/5-switch.swift
   :language: swift
   :caption: ./code/5-switch.swift

.. literalinclude:: ./code/6-for.swift
   :language: swift
   :caption: ./code/6-for.swift

.. literalinclude:: ./code/7-while.swift
   :language: swift
   :caption: ./code/7-while.swift

.. literalinclude:: ./code/8-func.swift
   :language: swift
   :caption: ./code/8-func.swift

.. literalinclude:: ./code/9-class.swift
   :language: swift
   :caption: ./code/9-class.swift

.. literalinclude:: ./code/10-enum.swift
   :language: swift
   :caption: ./code/10-enum.swift

.. literalinclude:: ./code/11-memory-layout.swift
   :language: swift
   :caption: ./code/11-memory-layout.swift

.. literalinclude:: ./code/12-weak-reference.swift
   :language: swift
   :caption: ./code/12-weak-reference.swift
