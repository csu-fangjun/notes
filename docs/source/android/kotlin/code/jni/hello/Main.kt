fun main() {
  var s = NativeSample()
  s.sayHello()
  var a : FloatArray = listOf(1.2f, 3.0f).toFloatArray()
  println(s.sum(a)) // 4.2

  a = floatArrayOf(3.0f, 4.0f, 5.0f)
  println(s.sum(a)) // 12.0

  a = FloatArray(100) {it.toFloat()}
  println(s.sum(a)) // 4950.0
}
