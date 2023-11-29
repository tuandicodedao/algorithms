#include <stdio.h>

int checkMajorityElement(int arr[], int n) {
    int count = 0;
    int candidate = 0;

    // Tìm ?ng viên cho ph?n t? tr?i
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Ki?m tra ?ng viên có ph?i ph?n t? tr?i hay không
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    // Ki?m tra s? l?n xu?t hi?n c?a ?ng viên
    if (count > n / 2) {
        return candidate;
    } else {
        return -1; // Không ch?a ph?n t? tr?i
    }
}

int main() {
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = checkMajorityElement(arr, n);

    if (result != -1) {
        printf("Phan tu troi la: %d\n", result);
    } else {
        printf("Khong co phan tu troi trong mang.\n");
    }

    return 0;
}

