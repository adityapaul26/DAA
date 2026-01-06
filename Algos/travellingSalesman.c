#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define N 4

int graph[N][N] = {
    {0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};

int travllingSalesman(int city, int visitedCount, bool visited[N]) {
    if (visitedCount == N)
        return graph[city][0]; // when last city is reached return to the
    // starting city

    int minCost = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;

            int cost = graph[city][i] +
                       travllingSalesman(i, visitedCount + 1, visited);
            if (cost < minCost)
                minCost = cost;

            visited[i] = false;
        }
    }
    return minCost;
}

int main() {
    bool visited[N] = {false};
    visited[0] = true;
    printf("minimum cost is: %d", travllingSalesman(0, 1, visited));
    return 0;
}