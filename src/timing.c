#include <time.h>
#include "timing.h"

time_t startTime, endTime;

void
startTimer() {
  startTime = time(NULL);
}

void
endTimer() {
  endTime = time(NULL);
}

long
getElapsedTime() {
  return endTime - startTime;
}