#include <stdio.h>
void shellSort(int arr[], int n) {
    int gap = n / 2;
    
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Mang ban dau: ");
    printArray(arr, n);
    
    shellSort(arr, n);
    
    printf("Mang sau khi sap xep: ");
    printArray(arr, n);
    
    return 0;
}

