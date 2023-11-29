#include<stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
	while (left <= right) {
		int mid = (right + left) / 2;
		if (arr[mid] == x) {
			return mid;
		} else if (arr[mid] < x) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return -1;
}

int main() {
	int arr[] = {1, 3, 4, 6, 7, 8, 22, 33};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 22;
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? printf("Khong tim thay trong mang") : printf("Co ton tai o vi tri %d", result);
	return 0;
}

