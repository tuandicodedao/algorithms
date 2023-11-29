#include <stdio.h>

void removeDuplicates(int arr[], int n) {
    // Kh?i t?o t?p h?p r?ng và m?ng k?t qu? r?ng
    int set[n];
    int result[n];
    int setSize = 0, resultSize = 0;

    // Duy?t qua t?ng ph?n t? trong m?ng ban d?u
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        
        // Ki?m tra xem ph?n t? dã t?n t?i trong t?p h?p chua
        for (int j = 0; j < setSize; j++) {
            if (arr[i] == set[j]) {
                isDuplicate = 1;
                break;
            }
        }

        // N?u ph?n t? không t?n t?i trong t?p h?p
        if (!isDuplicate) {
            // Thêm ph?n t? vào t?p h?p và m?ng k?t qu?
            set[setSize++] = arr[i];
            result[resultSize++] = arr[i];
        }
    }

    // In m?ng k?t qu? ch?a các ph?n t? phân bi?t
    printf("Mang ket qua: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    removeDuplicates(arr, n);

    return 0;
}

