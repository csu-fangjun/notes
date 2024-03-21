fun main() {
  var s = "nihaohello"
  println("s.length: ${s.length}")
  var bytes : ByteArray = "nihaohello".toByteArray()
  // for(b in bytes) {
  //   println(b.toUByte().toString(radix = 16))
  // }
  bytes.forEachIndexed{i, b ->
    println("$i, ${b.toUByte().toString(radix=16)}")
  }
/*
s.length: 7

0, e4
1, bd
2, a0
3, e5
4, a5
5, bd
6, 68
7, 65
8, 6c
9, 6c
10, 6f
*/
}
