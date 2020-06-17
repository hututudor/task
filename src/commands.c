#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "commands.h"
#include "file.h"

static void
displayHelp(void) {
  printf("task: A simple task runner program\n");
}

static void
runCommand(char *command) {
  char *fileData = loadFile("tasks");

  if (!fileData) {
    printf("Tasks file does not exists\n");
    return;
  }

  char *fileCommand = findCommandInFileData(fileData, command);

  if (!fileCommand) {
    printf("Command does not exists\n");
    return;
  }

  printf("> %s\n", fileCommand);
  system(fileCommand);
  printf("Done\n");
}

void
parseCommand(int argc, char *argv[]) {
  if (argc == 1) {
    displayHelp();
    return;
  }

  if (strcmp(argv[1], "help") == 0 ||
      strcmp(argv[1], "--help") == 0 ||
      strcmp(argv[1], "-h") == 0
    ) {
    displayHelp();
    return;
  }

  if (strcmp(argv[1], "run") == 0 ||
      strcmp(argv[1], "--run") == 0 ||
      strcmp(argv[1], "-r") == 0
    ) {
    if (argc == 2) {
      printf("Command needs an additional parameter\n");
      return;
    }

    runCommand(argv[2]);
    return;
  }

  printf("Unrecognized command\n");
}
