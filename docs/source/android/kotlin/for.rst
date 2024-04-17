for
===

.. code-block::

   val numbers = arrayOf(1, 2, 3)
   for (n in numbers) {
     println(n)
   }

   for (i in numbers.indices) {
     println(numbers[i])
   }

   for ((i, value) in numbers.withIndex()) {
     check(numbers[i] == value)
   }

   // 0 <= i < numbers.size
   for (i in 0 until numbers.size) {
     println(numbers[i])
   }


   // forEach
   val a = arrayOf(1, 2, 3)
   a.forEach(::println)
