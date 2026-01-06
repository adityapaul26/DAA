#include <limits.h>
#include <stdio.h>

#define V 5 // Number of vertices
#define E 8 // Number of edges

struct Edge {
    int src, dest, weight;
};

void printArray(int arr[]) {
    printf("Vertex \t Distance from source\n");
    for (int i = 0; i < V; i++)
        printf("   %d   ->   %d\n", i, arr[i]);
}

void bellmanFord(struct Edge edges[E], int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int wt = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                if (i == V - 1) {
                    printf("Graph contains negative weight cycle!\n");
                    return;
                }
                dist[v] = dist[u] + wt;
            }
        }
    }
// for (int j = 0; j < E; j++) {
    //     int u = edges[j].src;
    //     int v = edges[j].dest;
    //     int w = edges[j].weight;
    //     if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
    //         printf("Graph contains negative weight cycle!\n");
    //         return;
    //     }
    // }

    printArray(dist);
}

int main() {
    // Define graph as an edge list
    struct Edge edges[E] = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
                            {1, 4, 2},  {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    // struct Edge edges[4] = {
    //     {0, 1, 1}, {1, 2, -1}, {2, 3, -1}, {3, 0, -1}
    //     // This completes a cycle: 0 → 1 → 2 → 3 → 0 with total weight = 1 +
    //     // (-1) + (-1) + (-1) = -2
    // };

    int source = 0;
    bellmanFord(edges, source);
    return 0;
}