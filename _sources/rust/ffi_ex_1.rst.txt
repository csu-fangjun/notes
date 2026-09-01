ffi Example 1
==============

.. code-block::

   cargo new ffi_ex_1
   cd ffi_ex_1
   cargo add cc --build

.. code-block::

  $ cargo add cc --build
      Updating crates.io index
        Adding cc v1.2.27 to build-dependencies
               Features:
               - jobserver
               - parallel
      Updating crates.io index
       Locking 2 packages to latest Rust 1.87.0 compatible versions
        Adding cc v1.2.27
        Adding shlex v1.3.0

After creating and editing ``build.rs`` and ``./src/hello.c``:

.. code-block::

  $ tree .
  .
  ├── Cargo.lock
  ├── Cargo.toml
  ├── build.rs
  └── src
      ├── hello.c
      └── main.rs

  1 directory, 5 files

.. literalinclude:: ./code/ffi_ex_1/Cargo.toml
   :caption: ./Cargo.toml

.. literalinclude:: ./code/ffi_ex_1/build.rs
   :caption: ./build.rs
   :language: rust

.. literalinclude:: ./code/ffi_ex_1/src/hello.c
   :caption: ./src/hello.c
   :language: c

.. literalinclude:: ./code/ffi_ex_1/src/main.rs
   :caption: ./src/main.rs
   :language: rust

.. code-block:: bash

   cargo build -vv > a.txt 2>&1

.. literalinclude:: ./code/ffi_ex_1/a.txt
   :caption: a.txt

.. code-block:: bash

   tree . > b.txt

.. literalinclude:: ./code/ffi_ex_1/b.txt
   :caption: b.txt
