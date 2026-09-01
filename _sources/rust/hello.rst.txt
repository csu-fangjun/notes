hello
=====

.. literalinclude:: ./code/hello/hello.rs
   :language:  rust
   :caption:  ./code/hello/hello.rs

File extension is ``.rs``.

To build a statically linked executable, run::

  rust ./hello.rs

It generates an executable ``hello``::

  (py38) fangjuns-MacBook-Pro:hello fangjun$ file hello
  hello: Mach-O 64-bit executable x86_64

  (py38) fangjuns-MacBook-Pro:hello fangjun$ ls -lh hello
  -rwxr-xr-x  1 fangjun  staff   460K Jun 12 11:41 hello

  (py38) fangjuns-MacBook-Pro:hello fangjun$ otool -L ./hello
  ./hello:
          /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1319.0.0)

naming convention
-----------------

- ``my_var``
- ``my_func``

comments
--------
Like C/C++, it uses ``/**/`` and ``//``.

hello2 using cargo
------------------

.. code-block:: bash

   cargo new hello2


It creates a new directory ``hello2`` inside the current directory::

  (py38) fangjuns-MacBook-Pro:code fangjun$ tree hello2/
  hello2/
  ├── Cargo.toml
  └── src
      └── main.rs

  1 directory, 2 files

.. literalinclude:: ./code/hello2/Cargo.toml
   :caption: ./code/hello2/Cargo.toml

.. literalinclude:: ./code/hello2/src/main.rs
   :caption: ./code/hello2/src/main.rs

.. code-block:: bash

   cd hello2
   cargo build
   tree . > a.txt

.. literalinclude:: ./code/hello2/a.txt
   :caption: ./code/hello2/a.txt

.. code-block:: bash

   cd hello2
   cargo build --release
   tree . > b.txt

.. literalinclude:: ./code/hello2/b.txt
   :caption: ./code/hello2/b.txt

.. code-block:: bash

  (py38) fangjuns-MacBook-Pro:hello2 fangjun$ ls -lh target/debug/hello2 target/release/hello2
  -rwxr-xr-x  1 fangjun  staff   463K Jun 12 21:35 target/debug/hello2
  -rwxr-xr-x  1 fangjun  staff   388K Jun 12 21:37 target/release/hello2

  (py38) fangjuns-MacBook-Pro:hello2 fangjun$ strip target/debug/hello2 target/release/hello2

  (py38) fangjuns-MacBook-Pro:hello2 fangjun$ ls -lh target/debug/hello2 target/release/hello2
  -rwxr-xr-x  1 fangjun  staff   325K Jun 12 21:39 target/debug/hello2
  -rwxr-xr-x  1 fangjun  staff   325K Jun 12 21:39 target/release/hello2

.. code-block::

  (py38) fangjuns-MacBook-Pro:hello2 fangjun$ cargo run
      Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.00s
       Running `target/debug/hello2`
  Hello, world!

hello3
------

.. code-block:: bash

   cd code
   cargo new --lib hello3

.. code-block:: bash

  (py38) fangjuns-MacBook-Pro:code fangjun$ cargo new --lib hello3
      Creating library `hello3` package
  note: see more `Cargo.toml` keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html

  (py38) fangjuns-MacBook-Pro:code fangjun$ tree hello3
  hello3
  ├── Cargo.toml
  └── src
      └── lib.rs

  1 directory, 2 files


.. literalinclude:: ./code/hello3/Cargo.toml
   :caption: ./code/hello3/Cargo.toml

.. literalinclude:: ./code/hello3/src/lib.rs
   :caption: ./code/hello3/src/lib.rs

Pay attention to the function signature.

.. code-block:: bash

  (py38) fangjuns-MacBook-Pro:hello3 fangjun$ cargo test
     Compiling hello3 v0.1.0 (/Users/fangjun/open-source/notes/docs/source/rust/code/hello3)
      Finished `test` profile [unoptimized + debuginfo] target(s) in 0.81s
       Running unittests src/lib.rs (target/debug/deps/hello3-b178d4679cda4da3)

  running 1 test
  test tests::it_works ... ok

  test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.00s

     Doc-tests hello3

  running 0 tests

  test result: ok. 0 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.00s

use_hello3
----------

.. code-block:: bash

   cd code
   cargo new use_hello3

.. code-block:: bash

  (py38) fangjuns-MacBook-Pro:use_hello3 fangjun$ vim Cargo.toml
  (py38) fangjuns-MacBook-Pro:use_hello3 fangjun$ cargo run
       Locking 1 package to latest Rust 1.87.0 compatible version
     Compiling hello3 v0.1.0 (/Users/fangjun/open-source/notes/docs/source/rust/code/hello3)
     Compiling use_hello3 v0.1.0 (/Users/fangjun/open-source/notes/docs/source/rust/code/use_hello3)
      Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.71s
       Running `target/debug/use_hello3`
  Hello, world! 5

.. literalinclude:: ./code/use_hello3/Cargo.toml
   :caption: ./code/use_hello3/Cargo.toml

.. literalinclude:: ./code/use_hello3/src/main.rs
   :caption: ./code/use_hello3/src/main.rs


hello_comments
--------------

.. code-block::

   cd code
   cargo new hello_comment

.. literalinclude:: ./code/hello_comment/Cargo.toml
   :caption: ./code/hello_comment/Cargo.toml

.. literalinclude:: ./code/hello_comment/src/main.rs
   :caption: ./code/hello_comment/src/main.rs

.. code-block:: bash

  (py38) fangjuns-MacBook-Pro:hello_comment fangjun$ cargo doc
      Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.00s
     Generated /Users/fangjun/open-source/notes/docs/source/rust/code/hello_comment/target/doc/hello_comment/index.html
