#include <stdio.h>

int w[6] = {5, 10, 12, 13, 15, 18};
int x[6] = {0, 0, 0, 0, 0, 0};
int n = 6;
int target = 30;

void sumOfSubset(int sum, int k, int rem) {
    
    // left child
    x[k] = 1;
    if(sum + w[k] == target) {
        // print x
        for(int i = 0; i < n; i++) {
            if(x[i] == 1)
                printf("%d\t", w[i]);
        }
        printf("\n");
    }
    else if(sum + w[k] + w[k + 1] <= target) {
        // x[k] = 1;
        sumOfSubset(sum + w[k], k + 1, rem - w[k]);
    }

    // right child
    if(sum + rem - w[k] >= target && sum + w[k + 1] <= target){
        x[k] = 0;
        sumOfSubset(sum, k + 1, rem - w[k]);
    }
    
}

int main() {

    int total = 0;
    for(int i = 0; i < n; i++) {
        total += w[i];
    }
    printf("\nTotal: %d\n", total);

    sumOfSubset(0, 0, total);

    return 0;
}