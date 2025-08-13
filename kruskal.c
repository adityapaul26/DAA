#include <stdio.h>

#define V 5 // Number of vertices
#define E 7 // Number of edges

// Global arrays
int src[E] = {0, 0, 0, 1, 2, 1, 3};
int dest[E] = {1, 2, 3, 3, 3, 4, 4};
int weight[E] = {10, 6, 5, 15, 4, 7, 8};

int parent[V];

int find(int i) {
    if (i == parent[i])
        return i;
    find(parent[i]);
}

void doUnion(int x, int y) { parent[find(x)] = find(y); }

void sort() {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (weight[j] > weight[j + 1]) {
                int temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = dest[j];
                dest[j] = dest[j + 1];
                dest[j + 1] = temp;

                temp = src[j];
                src[j] = src[j + 1];
                src[j + 1] = temp;
            }
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i <= j) {
        while (arr[i] <= pivot && i <= high)
            i++;
        while (arr[j] > pivot && j > low)
            j--;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            temp = dest[j];
            dest[j] = dest[j + 1];
            dest[j + 1] = temp;

            temp = src[j];
            src[j] = src[j + 1];
            src[j + 1] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    temp = dest[low];
    dest[low] = dest[j];
    dest[j] = temp;

    temp = src[low];
    src[low] = src[j];
    src[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high)
        return;
    int part = partition(arr, low, high);
    quickSort(arr, low, part - 1);
    quickSort(arr, part + 1, high);
}

void kruskal() {
    int mstEdges = 0;

    for (int i = 0; i < V; i++)
        parent[i] = i;
    // sort(); sort using bubble sort
    quickSort(weight, 0, 6); // sort using quicksort
    printf("Edges\tWeight\n");
    for (int i = 0; i < E && mstEdges < V - 1; i++) {
        int u = src[i];
        int v = dest[i];

        if (find(u) != find(v)) {
            printf("%d-%d --> %d\n", u, v, weight[i]);
            doUnion(u, v);
            mstEdges++;
        }
    }
}

int main() {
    kruskal();
    return 0;
}