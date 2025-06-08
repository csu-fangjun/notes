#include "vlc/libvlc.h"
#include <iostream>
#include <stdio.h>

int main() {
  const char *version = libvlc_get_version();
  printf("libvlc version: %s\n", version);
  return 0;
}
