#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file.h"

char *loadFile(char *fileName) {
  FILE *file = fopen(fileName, "r");

  if (!file) {
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *data = malloc(fileSize + 1);
  fread(data, 1, fileSize, file);
  fclose(file);

  data[fileSize] = '\0';
  return data;
}

char *findCommandInFileData(char *fileData, char *command) {
  char *line;
  line = strtok(fileData, "\n");

  while (line) {
    if (strstr(line, command) == line) {
      char *actualCommand = strchr(line, ':');
      unsigned long index = 0;

      if (!actualCommand) {
        return NULL;
      }

      unsigned long commandLength = strlen(actualCommand);
      while (index < commandLength && (
        actualCommand[index] == ':' ||
        actualCommand[index] == ' ')) {
        index++;
      }

      return actualCommand + index;
    }

    line = strtok(NULL, "\n");
  }

  return NULL;
}
