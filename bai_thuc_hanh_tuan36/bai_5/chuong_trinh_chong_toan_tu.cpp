#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Complex {
    float real;
    float imaginary;
};

struct Complex addComplex(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

struct Vector {
    int length;
    int* elements;
};

struct Vector addVector(struct Vector a, struct Vector b) {
    if (a.length != b.length) {
        printf("Khong the cong hai vector co do dai khac nhau.\n");
        exit(1);
    }
    struct Vector result;
    result.length = a.length;
    result.elements = (int*)malloc(result.length * sizeof(int));
    for (int i = 0; i < result.length; i++) {
        result.elements[i] = a.elements[i] + b.elements[i];
    }
    return result;
}

struct Matrix {
    int rows;
    int cols;
    int** elements;
};

struct Matrix addMatrix(struct Matrix a, struct Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Khong the cong hai ma tran co kich thuoc khac nhau.\n");
        exit(1);
    }
    struct Matrix result;
    result.rows = a.rows;
    result.cols = a.cols;
    result.elements = (int**)malloc(result.rows * sizeof(int*));
    for (int i = 0; i < result.rows; i++) {
        result.elements[i] = (int*)malloc(result.cols * sizeof(int));
        for (int j = 0; j < result.cols; j++) {
            result.elements[i][j] = a.elements[i][j] + b.elements[i][j];
        }
    }
    return result;
}

int main() {
    struct Complex c1 = {2.5, 3.7};
    struct Complex c2 = {1.2, 2.3};
    struct Complex c3 = addComplex(c1, c2);
    printf("Tong hai so phuc: %.2f + %.2fi\n", c3.real, c3.imaginary);

  struct Vector v1;
v1.length = 3;
v1.elements = (int*)malloc(v1.length * sizeof(int));
v1.elements[0] = 1;
v1.elements[1] = 2;
v1.elements[2] = 3;

struct Vector v2;
v2.length = 3;
v2.elements = (int*)malloc(v2.length * sizeof(int));
v2.elements[0] = 4;
v2.elements[1] = 5;
v2.elements[2] = 6;

    struct Vector v3 = addVector(v1, v2);
    printf("Tong hai vector: ");
    for (int i = 0; i < v3.length; i++) {
        printf("%d ", v3.elements[i]);
    }
    printf("\n");

    struct Matrix m1;
    m1.rows = 2;
    m1.cols = 2;
    m1.elements = (int**)malloc(m1.rows * sizeof(int*));
    for (int i = 0; i < m1.rows; i++) {
        m1.elements[i] = (int*)malloc(m1.cols * sizeof(int));
    }
    int temp1[] = {1, 2};
    int temp2[] = {3, 4};
    memcpy(m1.elements[0], temp1, m1.cols * sizeof(int));
    memcpy(m1.elements[1], temp2, m1.cols * sizeof(int));

    struct Matrix m2;
    m2.rows = 2;
    m2.cols = 2;
    m2.elements = (int**)malloc(m2.rows * sizeof(int*));
    for (int i = 0; i < m2.rows; i++) {
        m2.elements[i] = (int*)malloc(m2.cols * sizeof(int));
    }
    int temp3[] = {5, 6};
    int temp4[] = {7, 8};
    memcpy(m2.elements[0], temp3, m2.cols * sizeof(int));
    memcpy(m2.elements[1], temp4, m2.cols * sizeof(int));

    struct Matrix m3 = addMatrix(m1, m2);
    printf("Tong hai ma tran:\n");
    for (int i = 0; i < m3.rows; i++) {
        for (int j = 0; j < m3.cols; j++) {
            printf("%d ", m3.elements[i][j]);
        }
        printf("\n");
    }

    // Giai phong bo nho da cap phat
    for (int i = 0; i < m1.rows; i++) {
        free(m1.elements[i]);
    }
    free(m1.elements);
    for (int i = 0; i < m2.rows; i++) {
        free(m2.elements[i]);
    }
    free(m2.elements);
    for (int i = 0; i < m3.rows; i++) {
        free(m3.elements[i]);
    }
    free(m3.elements);
    free(v1.elements);
    free(v2.elements);

    return 0;
}

