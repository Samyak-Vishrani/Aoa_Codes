#include <stdio.h>
#include <limits.h>

#define v 7     // num of vertices
#define e 11     // num of edges

void printBellman(int dist[]) {
    printf("Vertex\tDist from source\n");
    for(int i = 0; i < v; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}


// void bellman(int src, int from[], int to[], int weight[]) {
void bellman(int src, int edges[e][3]) {
    int dist[v];

    // initialize dist to infinity
    for(int i = 0; i < v; i++) {
        dist[i] = INT_MAX;
    }

    // dist of src = 0
    dist[src] = 0;

    // relax all edges (v-1) times
    for(int i = 0; i < v - 1; i++) {
        for(int j = 0; j < e; j++) {

            int from = edges[j][0];         // 1st column
            int to = edges[j][1];           // 2nd column
            int weight = edges[j][2];       // 3rd column
            
            if(dist[from] != INT_MAX && (dist[from] + weight) < dist[to]){
                dist[to] = dist[from] + weight;
            }
        }
    }

    // check for -ve weight cycle
    // above inner loop again
    for(int j = 0; j < e; j++) {

        int from = edges[j][0];         // 1st column
        int to = edges[j][0];           // 2nd column
        int weight = edges[j][0];       // 3rd column
        
        if(dist[from] != INT_MAX && dist[from] + weight < dist[to]){
            printf("\nGraph has -ve weight cycle");
            return;
        }
    }
    
    printBellman(dist);
    
}

int main() {

    int from[e] = {0, 0, 1, 1, 1, 3, 3, 4};
    int to[e] = {1, 2, 2, 3, 4, 2, 1, 3};
    int weight[e] = {-1, 4, 3, 2, 2, 5, 1, -3};

    int src = 0;

    // Each row: {source, destination, weight}
    // int edges[e][3] = {
    //     {0, 1, -1},
    //     {0, 2, 4},
    //     {1, 2, 3},
    //     {1, 3, 2},
    //     {1, 4, 2},
    //     {3, 2, 5},
    //     {3, 1, 1},
    //     {4, 3, -3}
    // };
    int edges[e][3] = {
        {0, 1, 1},
        {0, 2, 5},
        {0, 3, 5},
        {1, 4, -1},
        {2, 1, -2},
        {2, 4, 1},
        {3, 2, -2},
        {3, 5, -1},
        {4, 6, 3},
        {5, 6, 3}
    };

    // bellman(src, from, to, weight);
    bellman(src, edges);

    return 0;
}