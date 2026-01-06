#include <stdbool.h>
#include <stdio.h>

#define V 5

int graph[V][V] = {{0, 1, 0, 1, 0},
                   {1, 0, 1, 1, 1},
                   {0, 1, 0, 0, 1},
                   {1, 1, 0, 0, 1},
                   {0, 1, 1, 1, 0}};

int path[V];

bool isSafe(int pos, int v) {
    if (!graph[path[pos-1]][v])
        return false;
    for (int i = 0; i < V; i++) {
        if (path[i] == v)
            return false;
    }
    return true;
}

bool hamiltonian(int pos) {
    if (pos == V) {
        return graph[path[pos - 1]][path[0]];
    }

    for (int i = 0; i < V; i++) {
        if (isSafe(pos, i)) {
            path[pos] = i;

            if (hamiltonian(pos + 1))
                return true;

            path[pos] = -1;
        }
    }
    return false;
}

void findHamiltonianCycle() {
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (!hamiltonian(1)) {
        printf("No hamiltonian cycle detected!\n");
        return;
    }
    printf("Hamiltonian cycle exist!\n");
    for (int i = 0; i < V; i++)
        printf("%d -> ", path[i]);
    printf("%d", path[0]);
}

int main() {
    findHamiltonianCycle();
    return 0;
}