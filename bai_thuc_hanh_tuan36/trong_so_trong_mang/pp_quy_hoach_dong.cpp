#include <stdio.h>

int MaxSub(int a[], int n) {
    int smax = a[0];
    int maxendhere = a[0];
    int imax = 0;
    for (int i = 1; i < n; i++) {
        int u = maxendhere + a[i];
        int v = a[i];
        if (u > v) {
            maxendhere = u;
        } else {
            maxendhere = v;
            imax = i;
        }
        if (maxendhere > smax) {
            smax = maxendhere;
        }
    }
    return smax;
}

int main() {
    int a[] = {-2, 11, -4, 13, -5, 2};
    int n = sizeof(a) / sizeof(int);
    printf("Trong so lon nhat: %d", MaxSub(a, n));
    return 0;
}

