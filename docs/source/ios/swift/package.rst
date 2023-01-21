Package
=======

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
