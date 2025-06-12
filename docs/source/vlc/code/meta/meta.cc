#include "vlc/libvlc.h"
#include "vlc/libvlc_media.h"
#include <stdio.h>

int main() {
  const char *version = libvlc_get_version();
  const char *compiler_version = libvlc_get_compiler();
  const char *change_set = libvlc_get_changeset();
  printf("libvlc version: %s\n", version);
  printf("compiler version: %s\n", compiler_version);
  printf("changeset: %s\n", change_set);
  return 0;
}
