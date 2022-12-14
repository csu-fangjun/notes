#include <iostream>
#include <string>
int main() {
  std::string s = "你好hello";
  auto p = s.c_str();
  fprintf(stderr, "s.size: %d\n", (int)s.size());
  for (int i = 0; i != s.size(); ++i) {
    fprintf(stderr, "%d: %02x, %c\n", i, p[i], p[i]);
  }
  return 0;
  // UTF8 encoding of s is
  // \xe4\xbd\xa0\xe5\xa5\xbd\x68\x65\x6c\x6c\x6f
  //
  // UTF8 encoding of 你 is 0xe4 0xbd 0xa0
  // UTF8 encoding of 好 is 0xe5 0xa5 0xbd
  // UTF8 encoding of h is 0x68
  // UTF8 encoding of e is 0x65
  // UTF8 encoding of l is 0x6c
  // UTF8 encoding of o is 0x6f
}
/*
It prints:
s.size: 11

0: ffffffe4, �
1: ffffffbd, �
2: ffffffa0, �
3: ffffffe5, �
4: ffffffa5, �
5: ffffffbd, �
6: 68, h
7: 65, e
8: 6c, l
9: 6c, l
10: 6f, o
 */
