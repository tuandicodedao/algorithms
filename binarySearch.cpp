	//Nguyen Van Tuan 20216965 
#include<stdio.h>

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // n?u không tìm th?y giá tr? trong m?ng
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) {
        printf("Khong tim thay gia tri %d trong mang.", x);
    } else {
        printf("Gia tri %d co trong mang o vi tri %d.", x, result);
    }
    return 0;
}

