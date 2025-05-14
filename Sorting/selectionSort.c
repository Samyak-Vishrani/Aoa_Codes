// repeatedly select the minimum element from the unsorted part and move it to the beginning.

#include <stdio.h>

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // swap min with arr[i]
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;   
    }

    // print
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}


int main() {

    int n = 5;
    int arr[] = {5, 1, 10, 3, -7};
    selectionSort(arr, n);

    return 0;
}