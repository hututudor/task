#include <stdio.h>
#include "commands.h"

int main(int argc, char *argv[]) {
  parseCommand(argc, argv);

#if 0
  for (int i = 0; i < argc; i++) {
    printf("%s", argv[i]);
  }
#endif

  return 0;
}
