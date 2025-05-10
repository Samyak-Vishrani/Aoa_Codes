// PRIMS
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define v 5


void printMst(int parent[v], int graph[v][v]) {
    int weight = 0;
    printf("Edge \tWeight\n");
    for(int i = 1; i < v; i++) {
        printf("%d - %d \t %d\n", parent[i], i, graph[i][parent[i]] );
        weight += graph[i][parent[i]];
    }
    printf("Total Weight = %d", weight);
}

int minKey(int key[v], bool visited[v]) {
    int min = INT_MAX;
    int minIdx;
    
    // find min key which is not visited
    for(int i = 0; i < v; i++) {
        if(!visited[i] && key[i] < min) {
            min = key[i];
            minIdx = i;
        }
    }
    
    return minIdx;
}

void primMST(int graph[v][v]) {
    int parent[v];      // stores MST
    int key[v];         // key stores min value of tree
    bool visited[v];    // node visited or not
    
    // initialize all keys and visited
    for(int i = 0; i < v; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }
    
    // take 1st node
    key[0] = 0;
    parent[0] = -1;
    
    for (int i = 0; i < v - 1; i++) {
        int u = minKey(key, visited);
        
        visited[u] = true;
        
        for (int j = 0; j < v; j++) {
            // update key[]
            if(graph[u][j] && !visited[j] && graph[u][j] < key[j]){
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    
    printMst(parent, graph);
}

int main() {
    // Example graph (Adjacency Matrix)
    int graph[v][v] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}