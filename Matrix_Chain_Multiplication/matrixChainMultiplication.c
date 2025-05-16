#include <stdio.h>
#include <limits.h>

#define n 6

int m[n][n];
int s[n][n];

void matrixChainMulti(int p[]) {
    int i, j, k;

    // initialize diagonals to 0
    for(i = 0; i < n; i++){
        m[i][i] = 0;
    }
    
    // loops are like this as we have to fill 'm' diagonally
    for(int l = 2; l < n; l++) {
        for(i = 1; i < n - l + 1; i++) {
            j = i + l - 1;
            int min = INT_MAX;
            for(k = i; k < j; k++){
                int q = (m[i][k] + m[k + 1][j] + (p[i - 1] * p[j] * p[k]));
                if(q < min){
                    min = q;
                    m[i][j] = min;
                    s[i][j] = k;
                }
            }
        }
    }

    for(i = 1; i < n; i++) {
        for(j = 1; j < n; j++) {
            if (i > j)
                printf("-\t");
            else
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum Multiplication needed: %d", m[1][n - 1]);

}


void optimalparens(int i, int j) {
    if(i==j) {
        printf("A%d ", i);
    } else {
        printf(" ( ");
        optimalparens(i, s[i][j]);
        optimalparens(s[i][j]+1, j);
        printf(" ) ");
    }

}

int main() {

    int p[] = {4, 10, 3, 12, 20, 7};
    matrixChainMulti(p);
    // printMulti(1, n);
    printf("\n\n");
    optimalparens(1, n - 1);

}