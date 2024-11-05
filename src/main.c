#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../utils/arrays.h"
#include "../utils/sorts.h"
#include "../utils/timer.h"

void main() {
  srand(time(NULL));
  InfoArray infoArray = Array(100000);
  FillArray(&infoArray);

  timerSort(insertionSort, infoArray, "Bubble Sort");
}