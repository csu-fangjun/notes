fun testList() {
  val a = mutableListOf(1, 2, 3)
  println(a.javaClass) // class java.util.ArrayList

/*
  for((i, v) in a.withIndex()) {
    check(i + 1 == v)
  }
*/

  val b: List<Int> = a // view of a, no data is copied
  a[0] = 10 // b is also changed since b is a view of a
  check(b[0] == 10)

  check(a.first() == a[0])
  check(a.last() == a[a.size - 1])

  check(a.count() == a.size)
  check(10 in a)
  check(11 !in a)

  // append
  a.add(20)
  check(a.size == 4) // now there are 4 elements
  check(b.size == 4) // size of b is also changed
  check(a.last() == 20)

  a.add(1, 100) // at index 1, insert 100
  check(a[1] == 100)
  check(a[2] == 2)

  a.add(2)
  a.remove(2)  // remove the first occurrence of 2
  check(a.last() == 2)
}

fun testSet() {
  val a = mutableSetOf(1, 0, 2)
  println(a.javaClass) // class java.util.LinkedHashSet

  println(a)
  check(0 in a)
  check(3 !in a)

  check(a.count() == 3)
  check(a.size == 3)

  // remove a elment
  a.remove(0)
  check(0 !in a)

  a.add(0)
  check(0 in a)
}

fun testMap() {
  val a: MutableMap<Int, String> = mutableMapOf(0 to "zero", 1 to "one", 2 to "two")
  println(a.javaClass) // class java.util.LinkedHashMap

  check(a.count() == 3)
  check(a[0] == "zero")
  check(a.containsKey(0))

  a.remove(0)
  check(0 !in a)
  check(a.containsKey(0) == false)

  a.put(0, "zero")  // equivalent to a[0] = "zero"
  check(0 in a)
  check(a.containsKey(0))
}

fun main() {
  testList()
  testSet()
  testMap()
}
