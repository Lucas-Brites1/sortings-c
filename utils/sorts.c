#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "sorts.h"

// Bubble Sort
void bubbleSort(InfoArray infoArray) {
    for(int i = 0; i < infoArray.len - 1; i++) {
        for(int j = 0; j < infoArray.len - i - 1; j++) {
            if(infoArray.Array[j] > infoArray.Array[j + 1]) {
                int aux = infoArray.Array[j];
                infoArray.Array[j] = infoArray.Array[j + 1];
                infoArray.Array[j + 1] = aux;
            }
        }
    }
}

// Insertion Sort
void insertionSort(InfoArray infoArray) {
    for(int i = 1; i < infoArray.len; i++) {
        int key = infoArray.Array[i];
        int j = i - 1;
        while(j >= 0 && infoArray.Array[j] > key) {
            infoArray.Array[j + 1] = infoArray.Array[j];
            j--;
        }
        infoArray.Array[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(InfoArray infoArray) {
    for(int i = 0; i < infoArray.len - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < infoArray.len; j++) {
            if(infoArray.Array[j] < infoArray.Array[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int aux = infoArray.Array[i];
            infoArray.Array[i] = infoArray.Array[minIndex];
            infoArray.Array[minIndex] = aux;
        }
    }
}

// Merge Sort
void merge(InfoArray* infoArray, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = malloc(n1 * sizeof(int));
    int* R = malloc(n2 * sizeof(int));

    for(i = 0; i < n1; i++)
        L[i] = infoArray->Array[left + i];
    for(j = 0; j < n2; j++)
        R[j] = infoArray->Array[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = left; 

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            infoArray->Array[k] = L[i];
            i++;
        } else {
            infoArray->Array[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        infoArray->Array[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        infoArray->Array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(InfoArray* infoArray, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(infoArray, left, mid);
        mergeSort(infoArray, mid + 1, right);
        merge(infoArray, left, mid, right);
    }
}

// Quick Sort
int partition(InfoArray* infoArray, int low, int high) {
    int pivot = infoArray->Array[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++) {
        if(infoArray->Array[j] < pivot) {
            i++;
            int aux = infoArray->Array[i];
            infoArray->Array[i] = infoArray->Array[j];
            infoArray->Array[j] = aux;
        }
    }

    int aux = infoArray->Array[i + 1];
    infoArray->Array[i + 1] = infoArray->Array[high];
    infoArray->Array[high] = aux;

    return (i + 1);
}

void quickSort(InfoArray* infoArray, int low, int high) {
    if(low < high) {
        int pi = partition(infoArray, low, high);

        quickSort(infoArray, low, pi - 1);
        quickSort(infoArray, pi + 1, high);
    }
}

// Heap Sort
void heapify(InfoArray* infoArray, int n, int i) {
    int largest = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if(left < n && infoArray->Array[left] > infoArray->Array[largest])
        largest = left;

    if(right < n && infoArray->Array[right] > infoArray->Array[largest])
        largest = right;

    if(largest != i) {
        int aux = infoArray->Array[i];
        infoArray->Array[i] = infoArray->Array[largest];
        infoArray->Array[largest] = aux;

        heapify(infoArray, n, largest);
    }
}

void heapSort(InfoArray* infoArray) {
    int n = infoArray->len;

    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(infoArray, n, i);

    for(int i = n - 1; i > 0; i--) {
        int aux = infoArray->Array[0];
        infoArray->Array[0] = infoArray->Array[i];
        infoArray->Array[i] = aux;

        heapify(infoArray, i, 0);
    }
}
