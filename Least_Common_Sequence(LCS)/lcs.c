#include <stdio.h>
#include <stdbool.h>

#define xlen 6
#define ylen 6

int findMax(int a, int b) {
    return (a >= b ? a : b);
}

void printLcs(int arrow[xlen + 1][ylen + 1], char x[], int i, int j) {

    if(i == 0 || j == 0)
        return;
    if(arrow[i][j] == 1) {
        printLcs(arrow, x, i - 1, j - 1);
        printf("%c\t", x[i - 1]);
    }
    else if(arrow[i][j] == 2) {
        printLcs(arrow, x, i - 1, j);
    }
    else if(arrow[i][j] == 3) {
        printLcs(arrow, x, i, j - 1);
    }

}

void lcsFunc(char x[], char y[]) {

    int lcs[xlen + 1][ylen + 1];
    // 1 for diagonal, 2 for up, 3 for left
    int arrow[xlen + 1][ylen + 1];


    for(int i = 0; i < xlen + 1; i++) {
        for(int j = 0; j < ylen + 1; j++) {

            if(i == 0 || j == 0) {
                lcs[i][j] = 0;
            }
            else if(x[i - 1] == y[j - 1]) {
                // if equal then 1 + diagonal
                lcs[i][j] = (1 + lcs[i - 1][j - 1]);
                arrow[i][j] = 1;
            }
            else{
                int max = findMax(lcs[i - 1][j], lcs[i][j - 1]);
                lcs[i][j] = max;
                arrow[i][j] = ((max == lcs[i - 1][j]) ? 2 : 3);
            }
        }
    }
    
    printf("\n");
    printf("Lcs table:\n");
    for(int i = 0; i < xlen+1; i++){
            for(int j = 0; j < ylen+1; j++){
                printf("%d\t", lcs[i][j]);
            }
        printf("\n");
    }

    printf("\n\nLCS: \n");
    printLcs(arrow, x, xlen, ylen);

}

int main() {
    // char x[] = "AGGTAB";
    // char y[] = "GXTXAYB";
    char x[] = "ACBAED";
    char y[] = "ABCABE";

    lcsFunc(x, y);

    return 0;
}