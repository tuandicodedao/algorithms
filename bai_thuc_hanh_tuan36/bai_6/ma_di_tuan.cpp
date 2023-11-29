#include <stdio.h>

#define N 8

int board[N][N];
int moves[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

int solveKnightTour(int x, int y, int moveCount) {
    if (moveCount == N * N) {
        return 1;
    }

    for (int i = 0; i < 8; i++) {
        int nextX = x + moves[i][0];
        int nextY = y + moves[i][1];

        if (isSafe(nextX, nextY)) {
            board[nextX][nextY] = moveCount;
            if (solveKnightTour(nextX, nextY, moveCount + 1) == 1) {
                return 1;
            } else {
                board[nextX][nextY] = -1; // Quay lui
            }
        }
    }

    return 0;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Khoi tao ban co voi cac o chua di qua duoc danh dau bang -1
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1;
        }
    }

    // Dat quan ma vao o ban dau
    int startX = 0;
    int startY = 0;
    board[startX][startY] = 0;

    if (solveKnightTour(startX, startY, 1) == 1) {
        printf("Tim thay loi giai:\n");
        printBoard();
    } else {
        printf("Khong tim thay loi giai\n");
    }

    return 0;
}

