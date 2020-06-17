#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "commands.h"
#include "file.h"
#include "timing.h"
#include "colors.h"

static void
displayHelp(void) {
  printf("task: a simple cross-platform task runner program\n\n");
  printf("Commands: \n");
  printf("  - init(-i): Creates the tasks file in the current directory\n");
  printf("  - run(-r) <name>: Runs the command from the tasks file\n");
  printf("  - help(-h): Prints help\n");
}

static void
runCommand(char *command) {
  char *fileData = loadFile("tasks");

  if (!fileData) {
    printf("%sTasks file does not exists%s\n", COLOR_RED, COLOR_RESET);
    return;
  }

  char *fileCommand = findCommandInFileData(fileData, command);

  if (!fileCommand) {
    printf("%sCommand does not exists%s\n", COLOR_RED, COLOR_RESET);
    return;
  }

  printf("%s> %s%s\n\n", COLOR_YELLOW, fileCommand, COLOR_RESET);

  startTimer();
  system(fileCommand);
  endTimer();

  printf("%s\nDone in %ld seconds%s\n", COLOR_YELLOW, getElapsedTime(), COLOR_RESET);
}

static void
init() {
  system("touch tasks");
}

void
parseCommand(int argc, char *argv[]) {
  if (argc == 1) {
    displayHelp();
    return;
  }

  if (strcmp(argv[1], "help") == 0 ||
      strcmp(argv[1], "--help") == 0 ||
      strcmp(argv[1], "-h") == 0 ||
      strcmp(argv[1], "h") == 0
    ) {
    displayHelp();
    return;
  }

  if (strcmp(argv[1], "run") == 0 ||
      strcmp(argv[1], "--run") == 0 ||
      strcmp(argv[1], "-r") == 0 ||
      strcmp(argv[1], "r") == 0
    ) {
    if (argc == 2) {
      printf("%sCommand needs an additional parameter%s\n", COLOR_RED, COLOR_RESET);
      return;
    }

    runCommand(argv[2]);
    return;
  }

  if (strcmp(argv[1], "init") == 0 ||
      strcmp(argv[1], "--init") == 0 ||
      strcmp(argv[1], "-i") == 0 ||
      strcmp(argv[1], "i") == 0
    ) {
    init();
    return;
  }

  printf("%sUnrecognized command%s\n", COLOR_RED, COLOR_RESET);
}
