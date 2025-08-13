#include <stdio.h>

#define INF 99999 // A large number representing "infinity"

void flyodWarshall(int n, int graph[n][n]) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF &&
                    graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < n; i++) {
        if (graph[i][i] < 0) {
            printf("Negative cycle detected\n");
            return;
        }
    }

    // Print shortest path matrix
    printf("The shortest path matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4;
    int graph[4][4] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    flyodWarshall(n, graph);
    return 0;
}
