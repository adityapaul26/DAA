#include <limits.h>
#include <stdio.h>

void matrixChainOrder(int p[], int n) {
    int L, i, j, k, q;
    int m[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    printf("min number of multiplication req are:%d", m[1][n - 1]);
}

int main() {
    // Example: 3 matrices with dimensions 10x30, 30x5, 5x60
    // So p[] = {10, 30, 5, 60}
    int p[] = {10, 30, 5, 60};
    int n = sizeof(p) / sizeof(p[0]);

    matrixChainOrder(p, n);

    return 0;
}
