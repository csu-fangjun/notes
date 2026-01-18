Exercise 1 gcd
==============


simple gcd
----------

.. code-block::

   cargo new gcd_1
   cd gcd_1/src
   # edit main.rst

.. literalinclude:: ./code/gcd_1/src/main.rs

``cargo run`` prints::

       Compiling gcd_1 v0.1.0 (/Users/fangjun/open-source/notes/docs/source/rust/code/gcd_1)
        Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.12s
         Running `target/debug/gcd_1`
    gcd(6, 2) is 2

``cargo test`` prints::

     Compiling gcd_1 v0.1.0 (/Users/fangjun/open-source/notes/docs/source/rust/code/gcd_1)
      Finished `test` profile [unoptimized + debuginfo] target(s) in 0.08s
       Running unittests src/main.rs (target/debug/deps/gcd_1-74f037a3d4552c7d)

  running 1 test
  test test_gcd ... ok

  test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.00s


gcd from command line
---------------------

.. code-block::

   cargo new gcd_2
   cd gcd_2
   cd gcd_2/src
   # edit main.rs

.. literalinclude:: ./code/gcd_2/src/main.rs

``cargo run 5 15`` prints::

       Compiling gcd_2 v0.1.0 (/Users/fangjun/open-source/notes/docs/source/rust/code/gcd_2)
        Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.09s
         Running `target/debug/gcd_2 5 15`
    GCD of 5 and 15 is 5
