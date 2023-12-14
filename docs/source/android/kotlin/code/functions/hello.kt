fun double(x: Double): Double {
  return x * 2
}

// we can use trailing comma in the function parameters
//
@OptIn(kotlin.ExperimentalStdlibApi::class)
fun powerOf(
  x: Int,
  exponent: Int,
  ): Int {
    var n = 1
    for (i in 0 ..< exponent) {
      n *= x
    }
    return n
}

fun default(a: Int, b: Int = 2): Int {
  return a + b
}

// we can call a.size in setting the default value for b!!!
fun default2(a: Array<Float>, b: Int = a.size): Float {
  return a[0] + b
}

fun testDouble() {
  val x = double(2.5)
  check(x == 5.0)
}

fun testPowerOf() {
  val x = powerOf(2, 3)
  check(x == 8)
}

fun testDefault() {
  val x = default(1)
  check(x == 3)

  val y = default(1, 3)
  check(y == 4)
}

fun testDefault2() {
  val a: Array<Float> = arrayOf(1.5f, 2.0f, 3.0f)
  val b = default2(a)
  check(b == 1.5f+3)

  val c = default2(a, 10)
  check(c == 1.5f+10)
}

fun main() {
  testDouble()
  testPowerOf()
  testDefault()
  testDefault2()
}
