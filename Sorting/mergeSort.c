// It’s a divide and conquer algorithm.
// It divides the array into halves, sorts them recursively, and then merges them.

#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];           // temp array

    // copy data into temp arrays
    for(int i = 0; i < n1; i++) 
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j];
    
    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // copy remaining elements if any
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];

}


void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {

    int n = 5;
    int arr[] = {9, 1, 4, 3, -7};
    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}