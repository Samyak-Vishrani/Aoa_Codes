#include <stdio.h>
#include <limits.h>

#define v 4

void printFloyd(int dist[v][v]) {
    printf("Solution:\n");
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(dist[i][j] == INT_MAX){
                printf("x\t");
            }
            else{
                printf("%d\t", dist[i][j]);
            }
            
        }
        printf("\n");
    }
}

void floydWarshall(int graph[v][v]) {
    int dist[v][v];

    // initialize dist same as graph
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for(int k = 0; k < v; k++) {            // repeat process v times A1, A2, A3, A4...

        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                // if dist[i][k] + dist[k][i] < dist[i][j]
                if((dist[i][k] != INT_MAX) && (dist[k][j] != INT_MAX) && (dist[i][k] + dist[k][j] < dist[i][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printFloyd(dist);
}


int main() {
    int graph[v][v] = {
        {0,   3,  INT_MAX, 7},
        {8, 0,   2,  INT_MAX},
        {5, INT_MAX, 0,   1},
        {2, INT_MAX, INT_MAX, 0}
    };

    floydWarshall(graph);
    return 0;
}