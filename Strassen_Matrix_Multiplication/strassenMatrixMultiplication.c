#include <stdio.h>

int a[2][2] = {{1, 2}, {3, 4}};
int b[2][2] = {{3, 4}, {1, 2}};
int c[2][2];

int main() {

    int p = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    
    int q = (a[1][0] + a[1][1]) * (b[0][0]);
    int t = (a[0][0] + a[0][1]) * (b[1][1]);

    int r = (a[0][0]) * (b[0][1] - b[1][1]);
    int s = (a[1][1]) * (b[1][0] - b[0][0]);
    
    int u = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    int v = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
    
    c[0][0] = p + s - t + v;
    c[0][1] = r + t;
    c[1][0] = q + s;
    c[1][1] = p + r - q + u;

    printf("Answer: \n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}