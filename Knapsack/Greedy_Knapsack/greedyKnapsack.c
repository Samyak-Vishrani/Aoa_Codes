#include <stdio.h>
#include <stdbool.h>

#define n 6

void printKnapsack(double weight[], double profit[], double fractionChoosed[], double capacity, double capLeft) {
    double totalProfit = 0;
    
    printf("\nGreedy Knapsack\n\n");
    printf("i \tWeight Selected\tProfit Selected\n\n");
    for(int i = 0; i < n; i++) {
        if(fractionChoosed[i] != 0){
            printf("%d\t%f\t\t%f\n", (i+1), (weight[i] * fractionChoosed[i]), (profit[i] * fractionChoosed[i]));
            totalProfit += (profit[i] * fractionChoosed[i]);
        }
    }
    printf("\nTotal Profit: %f\n", totalProfit);
}

void fractionalKnapsack(double weight[n], double profit[n], double capacity) {

    double pwRatio[n];
    double fractionChoosed[n];
    double capLeft = capacity;

    // initialze pwRatio, fractionChoosed
    for(int i = 0; i < n; i++) {
        pwRatio[i] = profit[i] / weight[i];
        fractionChoosed[i] = 0.0;
    }

    // sort by p/w ratio
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            // descending order
            if(pwRatio[j] < pwRatio[j + 1]){
                // swap
                double temp = pwRatio[j];
                pwRatio[j] = pwRatio[j + 1];
                pwRatio[j + 1] = temp;

                // swap weights and profit too
                double tempW = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempW;

                double tempP = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempP;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(weight[i] <= capLeft) {
            fractionChoosed[i] = 1;
            capLeft -= weight[i];
        }
        else {
            fractionChoosed[i] = capLeft / weight[i];
            capLeft -= weight[i] * fractionChoosed[i];
        }
    }

    printKnapsack(weight, profit, fractionChoosed, capacity, capLeft);
}

int main() {

    double weight[n] = {7, 2, 3, 5, 3, 2};
    double profit[n] = {18, 5, 9, 10, 12, 7};
    double capacity = 13;

    fractionalKnapsack(weight, profit, capacity);

    return 0;
}