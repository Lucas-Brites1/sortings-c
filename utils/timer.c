#include <stdio.h>
#include "timer.h"

void timerSort(void (*sort)(InfoArray infoArray), InfoArray infoArray, char* funcName) {
  clock_t start, end;
  double finalTime;

  start = clock();
  sort(infoArray);
  end = clock();

  finalTime = ((double)(end-start) / CLOCKS_PER_SEC);
  printf("\n(%s) - %.6f segundos.", funcName, finalTime);
}
