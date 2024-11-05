#ifndef ARRAYS_H
#define ARRAYS_H

typedef struct InfoArray {
  int* Array;
  int len;
} InfoArray;

InfoArray Array(int len);
void FillArray(InfoArray* arrayInfo);
void PrintArray(InfoArray* arrayInfo);

#endif // ARRAYS_H