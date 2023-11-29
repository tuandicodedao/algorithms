#include <stdio.h>

void removeDuplicates(int arr[], int *size) {
    int uniqueArr[*size]; //  Mang phu de luu phan tu duy nhat
    int newSize = 0;

    for (int i = 0; i < *size; i++) {
        int j;
        for (j = 0; j < newSize; j++) {
            if (arr[i] == uniqueArr[j]) {
                break; // phan tu da ton tai trong mang phu khong luu nua
            }
        }

        if (j == newSize) {
            uniqueArr[newSize] = arr[i];
            newSize++;
        }
    }

    // cap nhat lai kich thuoc va sao chep cac phan tu duy nhat
    *size = newSize;
    for (int i = 0; i < newSize; i++) {
        arr[i] = uniqueArr[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    removeDuplicates(arr, &size);

    printf("Mang sau khi xoa cac phan tu trung nhau:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

