#ifndef SORTS_H
#define SORTS_H

#include "arrays.h"

void bubbleSort(InfoArray infoArray);
void insertionSort(InfoArray infoArray);
void selectionSort(InfoArray infoArray);
void mergeSort(InfoArray* infoArray, int left, int right);
void quickSort(InfoArray* infoArray, int low, int high);
void heapSort(InfoArray* infoArray);

#endif // SORTS_H
