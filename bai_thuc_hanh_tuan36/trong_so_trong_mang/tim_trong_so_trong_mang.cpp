// bai toan tim trong so lon nhat co trong mang
#include<stdio.h>

int main() {
    int arr[] = {-2, 11, -4, 13, -5, 2};
    int n = sizeof(arr) / sizeof(arr[0]); // tính s? ph?n t? trong m?ng
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) { // xóa d?u ch?m ph?y ? dây
                sum += arr[k]; // s?a tên bi?n t? a thành arr
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    printf("Max sum: %d", maxSum);
    return 0;
}

