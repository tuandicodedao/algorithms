#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int arr[], int n, int i) {
    int largest = i;      // Gán nút g?c là nút l?n nh?t
    int left = 2 * i + 1; // V? trí con trái trong m?ng
    int right = 2 * i + 2; // V? trí con ph?i trong m?ng

    // Ki?m tra xem con trái có l?n hon nút g?c hay không
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Ki?m tra xem con ph?i có l?n hon nút g?c hay không
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // N?u nút l?n nh?t không ph?i là nút g?c
    if (largest != i) {
        // Hoán d?i nút g?c v?i nút l?n nh?t
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // G?i d? quy maxHeapify trên cây con b? ?nh hu?ng
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    // Xây d?ng max-heap t? m?ng không du?c s?p x?p
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void insertNode(int arr[], int* n, int key) {
    // Tang kích thu?c m?ng
    (*n)++;

    int i = (*n) - 1;

    // Gán giá tr? key cho nút m?i du?c thêm vào
    arr[i] = key;

    // Ð?m b?o tính ch?t max-heap
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        // Hoán d?i nút v?i nút cha n?u nút m?i l?n hon nút cha
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
        // Không tìm th?y key trong m?ng
        return;
    }

    // Gán giá tr? c?a nút cu?i cùng cho nút c?n xóa
    arr[i] = arr[*n - 1];

    // Gi?m kích thu?c m?ng
    (*n)--;

    // Ð?m b?o tính ch?t max-heap
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
    printf("Sau khi thêm %d: ", key);
    printArray(arr, n);

    key = 5;
    deleteNode(arr, &n, key);
    printf("Sau khi xóa %d: ", key);
    printArray(arr, n);
    
	heapSort(arr, n);
    printf("M?ng sau khi s?p x?p: ");
    printArray(arr, n);
    return 0;
}

