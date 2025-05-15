#include <stdio.h>
#include <limits.h>

int max = INT_MIN, min = INT_MAX;

void maxMin(int arr[], int low, int high) {
    // int mid;
    int max1, min1, max2, min2;

    // if only 1 element
    if(low == high) {
        if(arr[low] > max) 
            max = arr[low];
        if(arr[low] < min) 
            min = arr[low];
        return;
    }
    // 2 elements
    else if(high == low + 1) {
        if(arr[low] > arr[high]) {
            if(arr[low] > max) max = arr[low];
            if(arr[high] < min) min = arr[high];
        }
        else {
            if(arr[high] > max) max = arr[high];
            if(arr[low] < min) min = arr[low];
        }
        return;
    }

    // recurssive call
    int mid = low + (high - low ) / 2;
    maxMin(arr, low, mid);
    maxMin(arr, mid + 1, high);
}

int main() {
    int arr[] = {3, 5, 1, 8, 2, 9, -2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    maxMin(arr, 0, n - 1);

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}