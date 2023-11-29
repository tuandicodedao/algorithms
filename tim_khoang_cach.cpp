#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findClosestNumbers(int arr[], int n) {
    // S?p x?p m?ng theo th? t? tang d?n
    qsort(arr, n, sizeof(int), cmpfunc);

    // Kh?i t?o giá tr? ban d?u cho minDiff và minIndex
    int minDiff = INT_MAX;
    int minIndex;

    // Duy?t qua t?ng c?p ph?n t? li?n k? trong m?ng
    for (int i = 0; i < n - 1; i++) {
        int diff = abs(arr[i] - arr[i+1]);
        if (diff < minDiff) {
            minDiff = diff;
            minIndex = i;
        }
    }

    // In ra c?p ph?n t? g?n nhau nh?t
    printf("Hai so gan nhau nhat la: %d va %d\n", arr[minIndex], arr[minIndex+1]);
}

int main() {
    int arr[] = {3, 9, 1, 17, 4, 11, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    findClosestNumbers(arr, n);

    return 0;
}

