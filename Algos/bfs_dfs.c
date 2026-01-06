#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Sample graph: 5 vertices
int graph[MAX][MAX];
int visited[MAX];

// ---------- DFS ----------
void dfs(int vertex, int n) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

// ---------- BFS ----------
void bfs(int start, int n) {
    int queue[MAX], front = 0, rear = 0;
    
    for (int i = 0; i < n; i++) visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// ---------- Main ----------
int main() {
    int n = 5; // Number of vertices

    // Sample undirected graph (adjacency matrix)
    // 0--1--2
    // |     |
    // 3-----4
    int sampleGraph[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    // Copy sample graph to global matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = sampleGraph[i][j];

    printf("DFS traversal starting from vertex 0:\n");
    for (int i = 0; i < n; i++) visited[i] = 0; // Reset visited
    dfs(0, n);

    printf("\n\nBFS traversal starting from vertex 0:\n");
    bfs(0, n);

    return 0;
}
