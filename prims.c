#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5

void printArray(int parent[V], int graph[V][V]) {
    printf("  Edge \t weight\n");
    for (int i = 1; i < V; i++)
        printf("%d---->%d\t %d\n", parent[i], i, graph[i][parent[i]]);
}

int selectMin(int key[V], bool visited[V]) {
    int minIndex = -1, minWeight = INT_MAX;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && key[i] < minWeight) {
            minIndex = i;
            minWeight = key[i];
        }
    }
    return minIndex;
}

void primsMST(int graph[V][V]) {
    int parent[V];   // this stores the actual mst
    int key[V];      // to store all the weights
    bool visited[V]; // marks all the visited nodes

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, visited[i] = false;

    parent[0] = -1;
    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = selectMin(key, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printArray(parent, graph);
}

int main() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    primsMST(graph);
    return 0;
}
