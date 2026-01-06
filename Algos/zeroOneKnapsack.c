#include <stdio.h>

// Function to return max of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Function to solve 0/1 Knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] =
                    max(K[i - 1][w], K[i - 1][w - wt[i - 1]] + val[i - 1]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    // Print the matrix (optional)
    // printf("DP Table:\n");
    // for (i = 0; i <= n; i++) {
    //     for (w = 0; w <= W; w++) {
    //         printf("%3d ", K[i][w]);
    //     }
    //     printf("\n");
    // }

    // Return the maximum value that can be put in the knapsack
    return K[n][W];
}

int main() {
    int val[] = {60, 100, 120}; // values of items
    int wt[] = {10, 20, 30};    // weights of items
    int W = 50;                 // knapsack capacity
    int n = sizeof(val) / sizeof(val[0]);

    int result = knapsack(W, wt, val, n);
    printf("\nMaximum value in knapsack = %d\n", result);

    return 0;
}
