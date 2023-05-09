Package
=======

See

- Using the Package Manager

  `<https://www.swift.org/getting-started/#using-the-package-manager>`_

- Package Manager

  `<https://www.swift.org/package-manager/>`_

- How Swift imports C APIs

  `<https://github.com/apple/swift/blob/main/docs/HowSwiftImportsCAPIs.md>`_

hello
-----

.. code-block:: bash

  mkdir hello
  cd hello
  swift package init

.. code-block:: bash

  .
  ├── Package.swift
  ├── README.md
  ├── Sources
  │   └── hello
  │       └── hello.swift
  └── Tests
      └── helloTests
          └── helloTests.swift

  4 directories, 4 files

.. literalinclude:: ./code/package/hello/Package.swift
   :language: swift
   :caption: ./code/package/hello/Package.swift

.. literalinclude:: ./code/package/hello/README.md
   :caption: ./code/package/hello/README

.. literalinclude:: ./code/package/hello/Sources/hello/hello.swift
   :language: swift
   :caption: ./code/package/hello/Sources/hello/hello.swift

.. literalinclude:: ./code/package/hello/Tests/helloTests/helloTests.swift
   :language: swift
   :caption: ./code/package/hello/Tests/helloTests/helloTests.swift

hello2
------

.. code-block:: bash

  mkdir hello2
  cd hello2
  swift package init --type executable

.. code-block:: bash

  .
  ├── Package.swift
  ├── README.md
  ├── Sources
  │   └── hello2
  │       └── hello2.swift
  └── Tests
      └── hello2Tests
          └── hello2Tests.swift

  4 directories, 4 files

.. literalinclude:: ./code/package/hello2/Package.swift
   :language: swift
   :caption: ./code/package/hello2/Package.swift

.. literalinclude:: ./code/package/hello2/README.md
   :caption: ./code/package/hello2/README

.. literalinclude:: ./code/package/hello2/Sources/hello2/hello2.swift
   :language: swift
   :caption: ./code/package/hello2/Sources/hello2/hello2.swift

.. literalinclude:: ./code/package/hello2/Tests/hello2Tests/hello2Tests.swift
   :language: swift
   :caption: ./code/package/hello2/Tests/hello2Tests/hello2Tests.swift

.. code-block:: bash

  swift run hello2

  Building for debugging...
  [3/3] Linking hello2
  Build complete! (0.88s)
  Hello, World!
