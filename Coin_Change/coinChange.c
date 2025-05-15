#include <stdio.h>

void printArr(int n, int amt, int table[n + 1][amt + 2]) {
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < amt + 2; j++){
            printf("%d \t", table[i][j]);
        }
        printf("\n");
    }
}

void coinChange(int coins[], int n, int amt) {
    int table[n + 1][amt + 2];

    // initialize table
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < amt + 2; j++){
            if(i == 0 && j > 0) {
                table[i][j] = j - 1;
            }
            else if(j == 0 && i != 0) {
                table[i][j] = coins[i - 1];
            }
            else if(j == 1) {
                table[i][j] = 0;
            }
            else {
                table[i][j] = 99;
            }
        }
    }
    table[0][0] = 0;
    printf("\n\n");
    printArr(n, amt, table);
    
    for(int i = 1; i < n + 1; i++) {
        for(int j = 2; j < amt + 2; j++) {

            if(i == 1) {
                table[i][j] = table[0][j] / table[i][0];
            }
            else if(j <= table[i][0]) {       // if j < coin val then copy above value
                table[i][j] = table[i - 1][j];
            }
            else {
                int above = table[i - 1][j];
                // int newVal = 1 + table[i][j - coins[i - 1]];
                int newVal = 1 + table[i][j - table[i][0]];         // formula: 1 + (j - coinVal)of that row
                table[i][j] = newVal < above ? newVal : above;
            }
        }
    }

    printf("\n\n");
    printArr(n, amt, table);
    printf("\nMin coins required for %d = %d\n", amt, table[n][amt + 1]);
}

int main() {

    int coins[] = {2, 3, 4};
    int n = sizeof(coins) / sizeof(coins[0]);

    int amt = 6;

    coinChange(coins, n, amt);

    return 0;
}