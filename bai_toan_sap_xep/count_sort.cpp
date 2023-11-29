#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    // Tim gia tri lon nhat trong mang
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // tao mang phu de dem so lan xuat hien cua cac phan tu
    int* count = (int*)calloc(max + 1, sizeof(int));

    // Ð?m s? l?n xu?t hi?n c?a t?ng ph?n t?
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Tính t?ng tích luy c?a m?ng count
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // T?o m?ng k?t qu?
    int* sortedArr = (int*)malloc(n * sizeof(int));

    // Ð?t các ph?n t? vào v? trí dúng trong m?ng k?t qu?
    for (int i = n - 1; i >= 0; i--) {
        sortedArr[--count[arr[i]]] = arr[i];
    }

    // Sao chép m?ng k?t qu? vào m?ng ban d?u
    for (int i = 0; i < n; i++) {
        arr[i] = sortedArr[i];
    }

    // Gi?i phóng b? nh?
    free(count);
    free(sortedArr);
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

    countingSort(arr, n);

    printf("M?ng sau khi s?p x?p: ");
    printArray(arr, n);

    return 0;
}

