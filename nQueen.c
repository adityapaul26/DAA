#include <stdbool.h>
#include <stdio.h>
#define MAX 20

bool isSafe(char board[MAX][MAX], int n, int col, int row) {
    // checking horizonatally
    for (int i = 0; i < n; i++) {
        if (board[row][i] == 'Q')
            return false;
    }

    // checking vertically
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    // checking left-diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    // checking right-diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    // return true;
}

void nQueen(char board[MAX][MAX], int n, int row) {
    // base case
    if (row == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n==================================\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, n, i, row)) {
            board[row][i] = 'Q';
            nQueen(board, n, row + 1);
            board[row][i] = '.';
        }
    }
}

int main() {

    char board[MAX][MAX];
    int n;

    printf("Enter the number of Queens: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    nQueen(board, n, 0);
}