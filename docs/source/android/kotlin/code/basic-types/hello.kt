fun testInt() {
  val a = 1
  check(a is Int)
  check(a == 1)

  val b = 1L
  check(b is Long)
  check(b == 1L)

  val c :Byte = -1
  check(c is Byte)
  check(c == (-1).toByte())

  val d: Short = 1
  check(d is Short)
  check(d == 1.toShort())

  val g = 0x0a
  check(g is Int)
  check(g == 10)

  val f = 0b00001000
  check(f is Int)
  check(f == 8)

  val h = 0b0000_1000
  check(h is Int)
  check(h == 8)

  val k = 1_000
  check(k is Int)
  check(k == 1000)

  val m = 1 / 2
  check(m is Int)
  check(m == 0)

  val n = 1 / 2.toFloat()
  check(n is Float)
  check(n == 0.5f)
}

fun testFloat() {
  val a = 1.0
  check(a is Double)
  check(a == 1.0)

  val b = 2.0F
  check(b is Float)
  check(b == 2.0F)
  check(b == (2.0).toFloat())

  // either f or F is ok
  val c = 2.0f
  check(c is Float)
  check(c == 2.0F)

  val d = (2.2F).toInt()
  check(d is Int)
  check(d == 2)
}


fun testBitwise() {
  // support only Int and Long
  val a = 0b01
  val b = 0b10

  val c = a or b // in C++: c = a | b

  check(c == 3)

  val d = a and b // in C++: d = a & b
  check(d == 0)

  val f = a shl 3 // in C++: a << 3
  check(f == 8)

  val g = b shr 1 // in C++: g = b >> 1
  check(g == 1)

  val h = a xor b // in C++: h = a ^ b
  check(h == 3)

  val k :Byte = 0b0100_0001
	// test inv()
}

fun testJavaClass() {
  val a = 1
	println(a.javaClass) // int
}

fun testBoolean() {
  val a = true
	val b = false
	val c: Boolean = true
	check(a)
	check(!b)
	check(c)

	val d = a && b
	check(d == false)

	val e = a || b
	check(e)
}

fun testChar() {
  // a char is 2-byte, utf-16
	val a = 'a'
	check(a is Char)
	check(a.isDigit() == false)

	val b = '\uff00'
	check(b is Char)

	val c = '9'
	check(c.isDigit() == true)

	check(Char.SIZE_BITS == 16)
	check('0'.code == 0x30)
	check('A'.lowercaseChar() == 'a')
	check('a'.uppercaseChar() == 'A')
}

fun testString() {
  // a sequence of Char, utf16
  // immutable
  val a = "abc"
  check(a + 1 == "abc1")

  // multi-line strings, like python
  val b = """
  line 1
  line 2
  """
  println(b)
/*

  line 1
  line 2

*/

  val c = """
  |line 1
  |line 2
  """.trimMargin()
  println(c)
/*
line 1
line 2
*/

  val d = """
  >line 1
  >line 2
  """.trimMargin(">")
  println(d)
/*
line 1
line 2
*/

  // format
  val k = String.format("%x %02x", 10, 10)
  check(k == "a 0a")
}

fun testArray() {
  val a = Array(3) {it}
  check(a[0] == 0)
  check(a[1] == 1)
  check(a[2] == 2)

  val b = arrayOf(0, 1, 2)
  check(a.contentEquals(b)) // we cannot use == since they save references

  a[0] = 10 // assign a value
  check(a[0] == 10)

  check(a.sum() == 10 + 1 + 2)

  check(a.joinToString() == "10, 1, 2")
}

fun shortArrayToByteArray() {
  val a: Array<Short> = arrayOf(0x0102, 0x0304)
  val b: Array<Byte> = Array(a.size * 2) {0}
  println(a.contentToString()) // [258, 772]
  println(b.contentToString()) // [0, 0, 0, 0]

  for (i in a.indices) {
    b[2*i] = (a[i].toInt() and 0xff).toByte()
    b[2*i+1] =((a[i].toInt() shr 8) and 0xff).toByte()
  }
  println(b.contentToString()) //  [2, 1, 4, 3]
}

fun byteArrayToShortArray() {
  val a: Array<Byte> = arrayOf(0x01, 0x02, 0x03, 0x04)
  val b: Array<Short> = Array(a.size / 2) {0}

  println(a.contentToString()) // [258, 772]
  println(b.contentToString()) // [0, 0, 0, 0]

  for (i in b.indices) {
    b[i] = (a[2*i].toInt() + (a[2*i+1].toInt() shl 8)).toShort()
  }
  check(b[0].toInt() == 0x0201)
  check(b[1].toInt() == 0x0403)
}

fun main() {
  testInt()
  testFloat()
  testBitwise()
	testJavaClass()
	testBoolean()
	testChar()
	testString()
  testArray()
  shortArrayToByteArray()
  byteArrayToShortArray()
}
