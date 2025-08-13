#include <stdbool.h>
#include <stdio.h>

#define V 4 // Number of vertices

// Function to print the color assignment
void printSolution(int color[]) {
    printf("Solution Exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
}

// Function to check if the current color assignment is safe
bool isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

// A recursive utility function to solve the problem
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        for (int i = 0; i < v; i++)
            printf("%d ", color[i]);
        return true; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

// Main function to solve the coloring problem
bool graphColoring(int graph[V][V], int m) {
    int color[V] = {0};

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist.\n");
        return false;
    }

    printSolution(color);
    return true;
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[V][V] = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};

    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;
}
