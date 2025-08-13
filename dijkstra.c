#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5

void printArray(int arr[]) {
    printf("Vertex \t Distance from source\n");
    for (int i = 0; i < V; i++)
        printf("   %d   ->   %d\n", i, arr[i]);
}

int select(int dist[V], bool visited[V]) {
    int minIndex = -1, minVal = INT_MAX;
    for (int i = 0; i < V; i++)
        if (!visited[i] && dist[i] < minVal) {
            minVal = dist[i];
            minIndex = i;
        }

    return minIndex;
}

void dijkstra(int graph[V][V], int src) {
    bool visited[V] = {false};
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int count = 1; count < V; count++) {
        int u = select(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printArray(dist);
}

int main() {
    int adjmatrix[V][V] = {{0, 10, 20, 0, 0},
                           {10, 0, 5, 15, 0},
                           {20, 5, 0, 30, 20},
                           {0, 15, 30, 0, 10},
                           {0, 0, 20, 10, 0}};

    dijkstra(adjmatrix, 0);
    return 0;
}