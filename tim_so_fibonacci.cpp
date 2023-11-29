#include <stdio.h>

int fibonacci(int n) {
    // Tru?ng h?p base
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);
    printf("So Fibonacci thu %d là %d\n", n, fibonacci(n));
    return 0;
}

