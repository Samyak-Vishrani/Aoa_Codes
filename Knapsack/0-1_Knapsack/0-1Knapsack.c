#include <stdio.h>
#include <stdbool.h>

#define n 6

int findMax(int a, int b) {
    return (a>b ? a : b);
}

void knapsack(int maxWeight, int weight[], int profit[]) {
    int i, w;
    int v[n + 1][maxWeight + 1];

    for(i = 0; i < n + 1; i++) {
        for(w = 0; w < maxWeight + 1; w++) {

            // i=0 w=0 all 0's
            if(i == 0 || w == 0)
                v[i][w] = 0;
            // before w = weight of new row, copy above row
            else if (w < weight[i - 1])
                v[i][w] = v[i - 1][w];
            else {
                // find max of v[i-1][w] (above row value) and v[i-1][w-weight[i]] + profit[i]
                v[i][w] = findMax(v[i - 1][w], (v[i - 1][w - weight[i - 1]] + profit[i - 1]));
            }
        }
    }

    for(i = 0; i < n + 1; i++) {
        for (int j = 0; j < maxWeight + 1; j++){
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }

    printf("\nMax Profit: %d\n", v[n][maxWeight]);

    // for objects included
    // check if above value is equal or not -> if not then obj include else not included
    int objIncluded[n] = {0, 0, 0, 0};
    w = maxWeight;
    for(int i = n; i > 0; i--) {
        if(w != 0 && v[i][w] != v[i - 1][w]) {
            objIncluded[i - 1] = 1;
            w -= weight[i - 1];
        }

    }

    for(i = 0; i < n; i++) {
        printf("%d\t", objIncluded[i]);
    }
}


int main() {
    int profit[] = {18, 5, 9, 10, 12, 7};
    int weight[] = {7, 2, 3, 5, 3, 2};
    int maxWeight = 13;
    // int profit[] = {1, 2, 5, 6};
    // int weight[] = {2, 3, 4, 5};
    // int maxWeight = 8;

    knapsack(maxWeight, weight, profit);

    return 0;
}