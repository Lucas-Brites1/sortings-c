#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrays.h"

InfoArray Array(int len) {
  InfoArray info;
  info.Array = malloc(sizeof(int) * len);
  if (!info.Array) {
    info.len = 0;
    return info;
  }
  info.len = len;
  return info;
}

void FillArray(InfoArray* arrayInfo) {
  if (arrayInfo->Array == NULL) {
    printf("Array não foi alocado corretamente.\n");
    return;
  }
  
  for (int i = 0; i < arrayInfo->len; i++) {
    int numero = rand() % 1000000;
    arrayInfo->Array[i] = numero;
  }
}

void PrintArray(InfoArray* arrayInfo) {
  if (arrayInfo->Array == NULL) {
    printf("Array não foi alocado corretamente.\n");
    return;
  }

  printf("Array:\n");
  for (int i = 0; i < arrayInfo->len; i++) {
    printf("%d ", arrayInfo->Array[i]);
  }
  printf("\n");
}

void FreeArray(InfoArray* arrayInfo) {
  if (arrayInfo->Array != NULL) {
    free(arrayInfo->Array);
    arrayInfo->Array = NULL;
  }
}
