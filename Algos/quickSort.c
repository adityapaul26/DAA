#include <stdio.h>

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
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high)
        return;
    int part = partition(arr, low, high);
    quickSort(arr, low, part - 1);
    quickSort(arr, part + 1, high);
}

int main() {
    // int arr[] = {4, 2, 6, 1, 9};
    int arr[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int n = 8;
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}