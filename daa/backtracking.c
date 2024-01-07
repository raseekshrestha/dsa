#include <stdio.h>
#include <stdbool.h>

#define N 8 // You can change N to solve for a different-sized chessboard

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col) {
    // Check the left side of the row
    for (int i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueensUtil(int board[N][N], int col) {
    if (col >= N) {
        printBoard(board);
        return true; // Successfully placed queens in all columns
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place queen

            // Recur to place rest of the queens
            res = solveNQueensUtil(board, col + 1) || res;

            board[i][col] = 0; // Backtrack if placing a queen here doesn't lead to a solution
        }
    }

    return res;
}

void solveNQueens() {
    int board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0; // Initialize the board
        }
    }

    if (!solveNQueensUtil(board, 0)) {
        printf("Solution does not exist.\n");
    }
}

int main() {
    solveNQueens();
    return 0;
}
