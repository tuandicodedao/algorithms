#include <stdio.h>

#define N 8

int board[N][N];

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] == 1 ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int row, int col) {
    int i, j;
    // Kiem tra cot trong hang hien tai
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return 0;
    }
    // kiem tra duong cheo
    i = row;
    j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1)
            return 0;
        i--;
        j--;
    }
    i = row;
    j = col;
    while (i >= 0 && j < N) {
        if (board[i][j] == 1)
            return 0;
        i--;
        j++;
    }
    return 1;
}

void solveNQueens(int row) {
    if (row == N) {
        printSolution();
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solveNQueens(row + 1);
            board[row][col] = 0; // Quay lui
        }
    }
}

int main() {
    solveNQueens(0);
    return 0;
}

