array
=====

.. code-block:: rust

  fn main() {
      let data: [i8; 3] = [0; 3];
      println!("{:?}", data);
      println!("{:#?}", data);
      println!("{data:?}");
      println!("{data:#?}");
      dbg!(data);
  }

For ``println!``, we have to use ``{:?}`` or ``{:#?}`` for arrays.

