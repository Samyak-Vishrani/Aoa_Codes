#include <stdio.h>
#include <stdlib.h>

#define N 4

int x[N];

int place(int k, int i) {
    for(int j = 0; j < k; j++) {
        if(x[j] == i || (abs(x[j] - i) == abs(j - k))){
            return 0;
        }
    }
    return 1;
}

void nQueens(int k, int n) {

    int i, j;

    for(int i = 0; i < n; i++) {
        if(place(k, i)) {
            x[k] = i;
            if(k == N - 1) {
                for(int j = 0; j < n; j++){
                    printf("%d\t", x[j] + 1);
                }
                printf("\n");
            }
            else {
                nQueens(k + 1, n);
            }
        }
    }

}

int main() {

    for(int i = 0; i < N; i++) {
        x[i] = 0;
    }

    nQueens(0, N);

    return 0;
}