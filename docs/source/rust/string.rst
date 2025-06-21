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
