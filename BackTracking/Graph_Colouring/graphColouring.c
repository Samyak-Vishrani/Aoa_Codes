#include <stdio.h>
#include <stdbool.h>

#define V 4  // Number of vertices
int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int m = 3;         // Number of colors
int x[V] = {0};    // Color assignments

void nextVal(int k){

    while(1) {
        x[k] = (x[k] + 1) % (m + 1);
        if(x[k] == 0)           // no valid colour
            return;

        int j;
        for(j = 0; j < V; j++) {
            if(graph[j][k] && x[k] == x[j])         // same color besides
                break;
        }
        if(j == V) {            // no conflict colour valid
            return;
        }
    }

}

void mColoring(int k) {
    while(1){
        nextVal(k);
        if(x[k] == 0)
            return;         // no color found

        if(k == V - 1) {
            printf("Possible Colours: \n");

            for(int i = 0; i < V; i++){
                printf("%d ", x[i]);
            }
            printf("\n\n");
        }
        else{
            mColoring(k + 1);
        }
    }
}

int main() {

    mColoring(0);

    return 0;
}