String
======

.. code-block:: rust

   let mut s = String::from("hello");
   s.push_str(", world"); // hello, world

.. code-block:: rust

  fn main() {
      let s = r"this is a raw string";
      let s2 = r##"this is a "second" string"##;
      let s3 = "this is a \"third\" string";
      dbg!(s);
      dbg!(s2);
      dbg!(s3);
  }

See

  - `<https://doc.rust-lang.org/reference/tokens.html#characters-and-strings>`_
  - `str <https://doc.rust-lang.org/core/primitive.str.html>`_
  - `CString <https://doc.rust-lang.org/std/ffi/struct.CString.html>`_
  - `CStr <https://doc.rust-lang.org/std/ffi/struct.CStr.html>`_
  - `String <https://doc.rust-lang.org/std/string/struct.String.html>`_

.. literalinclude:: ./code/str/src/main.rs
   :caption: main.rs
   :language: rust
