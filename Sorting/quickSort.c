#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int part = partition(arr, low, high);

        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

int main() {

    int n = 5;
    int arr[] = {9, 1, 4, 3, -7};
    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}