for
===

.. code-block:: rust

   for x in 1..5 {
     dbg!(x);
   }
   // it prints: x=1, x=2, x=3, x=4
   // note that 5 is exclusive
   // also note x is not pre-defined. Outside of the for loop,
   // x is not accessible

.. code-block:: rust

   for x in 1..=5 {
       dbg!(x);
   }
   // now 5 is inclusive

.. code-block:: rust

   for elem in [2, 4, 6] {
      dbg!(elem);
   }
   // iterate an array

break with a label
------------------

.. code-block:: rust

  fn main() {
      let data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
      let target = 2;
      let mut searched = 0;
      'out_label: for i in 0..=2 {
          for k in 0..=2 {
              searched += 1;
              if data[i][k] == target {
                  break 'out_label;
              }
          }
      }
      dbg!(searched);
  }
