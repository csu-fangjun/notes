fun testIf() {
  val a = 1
  val b = 2
  var max = -1
  if (a > b) {
    max = a
  } else {
    max = b
  }
  check(max == b)

  // if can be used in an expression
  val min = if (a < b) {a} else {b}
  check(min == a)
}

fun testWhen() {
  val a = 1
  var c: Int
  when(a) {
    1 -> c = 10
    2 -> c = 20
    else -> c = 30
  }
  check(c == 10)

  val d = when {
    a < 0 -> 3
    a == 0 -> 10
    a == 1 -> 30
    else -> 5
  }
  check(d == 30)

  val k: Any = 1
  val b = when (k) {
    is Int -> 10
    is Float -> 20
    else -> 30
  }
  check(b == 10)
}

@OptIn(kotlin.ExperimentalStdlibApi::class)
fun testRange() {
  check(5 in 0..5) // [0,5]
  check(5 !in 0..<5) // [0,5)

  check(4 in 4 downTo 1)  // [4,3,2,1]
  check(1 in 4 downTo 1)  // [4,3,2,1]

  check(0 in 0..5 step 3)
  check(1 !in 0..5 step 3)
  check(2 !in 0..5 step 3)
  check(3 in 0..5 step 3)
  check(4 !in 0..5 step 3)
  check(5 !in 0..5 step 3)

  check(5 in 5 downTo 0 step 3)
  check(4 !in 5 downTo 0 step 3)
  check(3 !in 5 downTo 0 step 3)
  check(2 in 5 downTo 0 step 3)
  check(1 !in 5 downTo 0 step 3)
  check(0 !in 5 downTo 0 step 3)
}

fun testFor() {
  var a: Array<Int> = Array(5) {0}

  for (i in 0..4) {
    a[i] = i
  }

  check(a[0] == 0)
  check(a[1] == 1)
  check(a[2] == 2)
  check(a[3] == 3)

  for(i in 4 downTo 0) {
    a[i] = 4 - i
  }

  check(a[4] == 0);
  check(a[3] == 1);
  check(a[2] == 2);
  check(a[1] == 3);
  check(a[0] == 4);

  for (i in a.indices) {
    when (i) {
      0 -> check(a[i] == 4)
      1 -> check(a[i] == 3)
      2 -> check(a[i] == 2)
      3 -> check(a[i] == 1)
      4 -> check(a[i] == 0)
    }
  }

  for ((i, value) in a.withIndexes()) {
    when (i) {
      0 -> check(value == 4)
      1 -> check(value == 3)
      2 -> check(value == 2)
      3 -> check(value == 1)
      4 -> check(value == 0)
    }
  }
}

fun main() {
  testIf()
  testWhen()
  testRange()
  testFor()
}
