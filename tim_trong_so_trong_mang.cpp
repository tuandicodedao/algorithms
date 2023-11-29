// bai toan tim trong so lon nhat co trong mang
#include<stdio.h>

int main() {
    int arr[] = {-2, 11, -4, 13, -5, 2};
    int n = sizeof(arr) / sizeof(arr[0]); // tinh so phan tu trong mang
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) { 
                sum += arr[k]; 
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    printf("Max sum: %d", maxSum);
    return 0;
}

