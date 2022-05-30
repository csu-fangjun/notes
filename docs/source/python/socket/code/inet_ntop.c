
#include <arpa/inet.h>
#include <stdio.h>

int main() {
  struct in_addr addr;
  uint8_t *p = (uint8_t *)&addr.s_addr;
  p[0] = 192;
  p[1] = 168;
  p[2] = 1;
  p[3] = 2;
  char buf[INET_ADDRSTRLEN];
  const char *ret = inet_ntop(AF_INET, &addr.s_addr, buf, sizeof(buf));
  printf("%s\n", buf);
  printf("%p, %p\n", buf, ret);
  return 0;
}
#if 0
192.168.1.2
0x7ffc808b5e80, 0x7ffc808b5e80
#endif
