#include <arpa/inet.h>
#include <stdio.h>

int main() {
  struct in_addr addr;
  int res = inet_pton(AF_INET, "192.168.1.2", &addr);
  printf("%08x\n", addr.s_addr);
  printf("192: %x\n", 192);
  printf("168: %x\n", 168);
  printf("1: %x\n", 1);
  printf("2: %x\n", 2);
  return 0;
}
#if 0
./inet_pton
0201a8c0
192: c0
168: a8
1: 1
2: 2
#endif
