#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int arr[], int n, int i) {
    int largest = i;      // G�n n�t g?c l� n�t l?n nh?t
    int left = 2 * i + 1; // V? tr� con tr�i trong m?ng
    int right = 2 * i + 2; // V? tr� con ph?i trong m?ng

    // Ki?m tra xem con tr�i c� l?n hon n�t g?c hay kh�ng
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Ki?m tra xem con ph?i c� l?n hon n�t g?c hay kh�ng
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // N?u n�t l?n nh?t kh�ng ph?i l� n�t g?c
    if (largest != i) {
        // Ho�n d?i n�t g?c v?i n�t l?n nh?t
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // G?i d? quy maxHeapify tr�n c�y con b? ?nh hu?ng
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    // X�y d?ng max-heap t? m?ng kh�ng du?c s?p x?p
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void insertNode(int arr[], int* n, int key) {
    // Tang k�ch thu?c m?ng
    (*n)++;

    int i = (*n) - 1;

    // G�n gi� tr? key cho n�t m?i du?c th�m v�o
    arr[i] = key;

    // �?m b?o t�nh ch?t max-heap
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        // Ho�n d?i n�t v?i n�t cha n?u n�t m?i l?n hon n�t cha
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

void deleteNode(int arr[], int* n, int key) {
    int i;
    for (i = 0; i < *n; i++) {
        if (arr[i] == key) {
            break;
        }
    }

    if (i == *n) {
        // Kh�ng t�m th?y key trong m?ng
        return;
    }

    // G�n gi� tr? c?a n�t cu?i c�ng cho n�t c?n x�a
    arr[i] = arr[*n - 1];

    // Gi?m k�ch thu?c m?ng
    (*n)--;

    // �?m b?o t�nh ch?t max-heap
    maxHeapify(arr, *n, i);
}
void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeapify(arr, i, 0);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 6, 3, 5, 4, 3, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("M?ng ban d?u: ");
    printArray(arr, n);

    buildMaxHeap(arr, n);

    printf("Max-heap: ");
    printArray(arr, n);

    int key = 7;
    insertNode(arr, &n, key);
    printf("Sau khi th�m %d: ", key);
    printArray(arr, n);

    key = 5;
    deleteNode(arr, &n, key);
    printf("Sau khi x�a %d: ", key);
    printArray(arr, n);
    
	heapSort(arr, n);
    printf("M?ng sau khi s?p x?p: ");
    printArray(arr, n);
    return 0;
}

