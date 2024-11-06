#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000  // Definindo o tamanho do array para 100.000 elementos

// Função para o algoritmo Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Seleciona o elemento atual para comparação
        int j = i - 1;
        
        // Move os elementos maiores que "key" uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;  // Insere "key" na posição correta
    }
}

// Função para o algoritmo Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Percorre o array, comparando pares de elementos adjacentes
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos caso estejam fora de ordem
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para o algoritmo Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;  // Assume que o menor elemento é o i-ésimo
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;  // Atualiza o índice do menor elemento
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Funções auxiliares para o algoritmo Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;  // Tamanho do subarray esquerdo
    int n2 = r - m;      // Tamanho do subarray direito

    int L[n1], R[n2];  // Arrays temporários para armazenar os elementos divididos

    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Intercala os arrays temporários de volta para o array original
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L, se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R, se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;  // Encontra o ponto médio
        mergeSort(arr, l, m);     // Ordena a primeira metade
        mergeSort(arr, m + 1, r); // Ordena a segunda metade
        merge(arr, l, m, r);      // Intercala as duas metades
    }
}

// Funções auxiliares para o algoritmo Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Define o último elemento como pivô
    int i = (low - 1);      // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;  // Incrementa o índice do menor elemento
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;  // Coloca o elemento menor à esquerda do pivô
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;  // Coloca o pivô na posição correta
    return (i + 1);    // Retorna o índice do pivô
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Índice de particionamento
        quickSort(arr, low, pi - 1);  // Ordena os elementos à esquerda do pivô
        quickSort(arr, pi + 1, high); // Ordena os elementos à direita do pivô
    }
}

// Funções auxiliares para o algoritmo Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;       // Assume o nó atual como o maior
    int left = 2 * i + 1;  // Filho à esquerda
    int right = 2 * i + 2; // Filho à direita

    if (left < n && arr[left] > arr[largest])
        largest = left;  // Atualiza o maior valor

    if (right < n && arr[right] > arr[largest])
        largest = right; // Atualiza o maior valor

    // Se o maior valor não for a raiz, troca e continua heapificando
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);  // Heapifica a subárvore
    }
}

void heapSort(int arr[], int n) {
    // Constrói o heap (max-heap)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai um elemento por vez do heap
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;  // Move o maior elemento para o final
        heapify(arr, i, 0);  // Heapifica o heap reduzido
    }
}

// Função para medir o tempo de execução de algoritmos que não requerem índices extras
void measureExecutionTime(void (*sortFunction)(int[], int), int arr[], int n, const char* sortName) {
    int* arrCopy = malloc(n * sizeof(int));  // Cria uma cópia do array para evitar reutilização de dados ordenados
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i];

    clock_t start = clock();  // Inicia a medição de tempo
    sortFunction(arrCopy, n); // Chama a função de ordenação
    clock_t end = clock();    // Finaliza a medição de tempo

    double executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do %s para %d elementos: %f segundos\n", sortName, n, executionTime);
    free(arrCopy);  // Libera a memória da cópia do array
}

// Função para medir o tempo de execução de algoritmos que requerem índices extras (ex: mergeSort, quickSort)
void measureExecutionTimeRange(void (*sortFunction)(int[], int, int), int arr[], int n, const char* sortName) {
    int* arrCopy = malloc(n * sizeof(int));  // Cria uma cópia do array
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i];

    clock_t start = clock();  // Inicia a medição de tempo
    sortFunction(arrCopy, 0, n - 1); // Chama a função de ordenação com índices
    clock_t end = clock();    // Finaliza a medição de tempo

    double executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do %s para %d elementos: %f segundos\n", sortName, n, executionTime);
    free(arrCopy);  // Libera a memória da cópia do array
}

// Função principal
int main() {
    int arr[SIZE];
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000000;  // Gera um array com elementos aleatórios
    }

    // Medindo o tempo de execução de cada algoritmo
    measureExecutionTime(insertionSort, arr, SIZE, "Insertion Sort");
    measureExecutionTime(bubbleSort, arr, SIZE, "Bubble Sort");
    measureExecutionTime(selectionSort, arr, SIZE, "Selection Sort");
    measureExecutionTimeRange(mergeSort, arr, SIZE, "Merge Sort");
    measureExecutionTimeRange(quickSort, arr, SIZE, "Quick Sort");
    measureExecutionTime(heapSort, arr, SIZE, "Heap Sort");

    return 0;
}
