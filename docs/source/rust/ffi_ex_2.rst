ffi Example 2
=============

.. code-block::

  (py38) fangjuns-MacBook-Pro:code fangjun$ cargo new ffi_ex_2
      Creating binary (application) `ffi_ex_2` package
  note: see more `Cargo.toml` keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html

  (py38) fangjuns-MacBook-Pro:code fangjun$ cd ffi_ex_2/

  (py38) fangjuns-MacBook-Pro:ffi_ex_2 fangjun$ cargo add cc --build
      Updating crates.io index
        Adding cc v1.2.27 to build-dependencies
               Features:
               - jobserver
               - parallel
      Updating crates.io index
       Locking 2 packages to latest Rust 1.87.0 compatible versions

Now create ``build.rs`` and ``src/hello.c`` and change ``src/main.rs``.

.. literalinclude:: ./code/ffi_ex_2/Cargo.toml
   :caption: Cargo.toml

.. literalinclude:: ./code/ffi_ex_2/build.rs
   :caption: build.rs
   :language: rust

.. literalinclude:: ./code/ffi_ex_2/src/hello.c
   :caption: src/hello.c
   :language: c

.. literalinclude:: ./code/ffi_ex_2/src/main.rs
   :caption: src/main.rs
   :language: rust
