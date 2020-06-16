#include <stdio.h>
#include <string.h>

#include "commands.h"

static void
displayHelp(void) {
  printf("task: A simple task runner program\n");
}

void
parseCommand(int argc, char *argv[]) {
  if (argc == 1) {
    displayHelp();
  }

  if (strcmp(argv[1], "help") == 0 ||
      strcmp(argv[1], "--help") == 0 ||
      strcmp(argv[1], "-h") == 0
    ) {
    displayHelp();
  }
}
