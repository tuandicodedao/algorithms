#include <stdio.h>

void findSubarray(int a[], int n, int M) {
    int start = 0; // V? tr� b?t d?u c?a m?ng con
    int end = 0; // V? tr� k?t th�c c?a m?ng con
    int currentSum = a[0]; // T?ng t?m th?i c?a m?ng con

    while (end < n) {
        // N?u t?ng t?m th?i b?ng M, in ra m?ng con v� tang v? tr� b?t d?u l�n 1
        if (currentSum == M) {
            for (int i = start; i <= end; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
            currentSum -= a[start];
            start++;
        }
        // N?u t?ng t?m th?i nh? hon M, tang v? tr� k?t th�c l�n 1 v� c?ng th�m ph?n t? ti?p theo v�o t?ng t?m th?i
        else if (currentSum < M) {
            end++;
            currentSum += a[end];
        }
        // N?u t?ng t?m th?i l?n hon M, gi?m t?ng t?m th?i di ph?n t? d?u ti�n v� tang v? tr� b?t d?u l�n 1
        else {
            currentSum -= a[start];
            start++;
        }
    }
}

int main() {
    int a[] = {1, 4, 7, 3, 9, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int M = 15;

    findSubarray(a, n, M);

    return 0;
}

