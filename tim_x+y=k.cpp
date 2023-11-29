#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int findPair(int X[], int nX, int Y[], int nY, int k) {
	
    // S?p x?p t?p X và t?p Y theo th? t? tang d?n
    qsort(X, nX, sizeof(int), compare);
    qsort(Y, nY, sizeof(int), compare);

    // Kh?i t?o hai con tr?
    int i = 0;               // Con tr? cho t?p X
    int j = nY - 1;          // Con tr? cho t?p Y

    while (i < nX && j >= 0) {
        int sum = X[i] + Y[j];
        if (sum == k) {
            return 1;  // Tìm du?c c?p s? (x, y) th?a mãn x + y = k
        } else if (sum > k) {
            j--;  // Gi?m con tr? c?a t?p Y d? gi?m t?ng sum
        } else {
            i++;  // Tang con tr? c?a t?p X d? tang t?ng sum
        }
    }
    return 0;  // Không tìm du?c c?p s? (x, y) th?a mãn x + y = k
}


int main() {
    int X[] = {1, 2, 3, 4, 5};
    int nX = sizeof(X) / sizeof(X[0]);

    int Y[] = {6, 7, 8, 9, 10};
    int nY = sizeof(Y) / sizeof(Y[0]);

    int k = 13;

    if (findPair(X, nX, Y, nY, k)) {
        printf("Có t?n t?i c?p s? (x, y) th?a mãn x + y = %d\n", k);
    } else {
        printf("Không t?n t?i c?p s? (x, y) th?a mãn x + y = %d\n", k);
    }

    return 0;
}

