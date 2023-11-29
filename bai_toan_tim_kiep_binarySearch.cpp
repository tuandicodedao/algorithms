#include<stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
	if (right >= left) {
		int mid = (left + right) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		if (arr[mid] > x) {
			return binarySearch(arr, left, mid - 1, x);
		} else {
			return binarySearch(arr, mid + 1, right, x);
		}
	} else {
		return -1;
	}
}

int main() {
	int arr[] = {1, 4, 5, 7, 8, 23, 35, 76};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 35;
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? printf("Khong tim thay trong mang") : printf("Co ton tai o vi tri %d", result);
	return 0;
}

