// left part of array is always sorted

#include <stdio.h>

void insertionSort(int arr[], int n) {

    int key;

    for(int i = 1; i < n; i++) {
        key = arr[i];
        int j = i - 1;

        while(j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // print
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}

int main() {
    int n = 5;
    int arr[] = {5, 1, 9, 3, -7};
    insertionSort(arr, n);
}