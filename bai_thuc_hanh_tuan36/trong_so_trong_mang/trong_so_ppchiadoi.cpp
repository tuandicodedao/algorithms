#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int max_cross_sum(int arr[], int l, int m, int r) {
    int sum = 0;
    int left_sum = -1000;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }
    sum = 0;
    int right_sum = -1000;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }
    return left_sum + right_sum;
}

int max_subarray_sum(int arr[], int l, int r) {
    if (l == r) {
        return arr[l];
    }
    int m = (l + r) / 2;
    int left_sum = max_subarray_sum(arr, l, m);
    int right_sum = max_subarray_sum(arr, m + 1, r);
    int cross_sum = max_cross_sum(arr, l, m, r);
    return max(max(left_sum, right_sum), cross_sum);
}

int main() {
    int arr[] = {-2, 11, -4, 13, -5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = max_subarray_sum(arr, 0, n - 1);
    printf("Trong so lon nhat: %d", max_sum);
    return 0;
}

