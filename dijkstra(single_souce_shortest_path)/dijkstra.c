#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define v 5

void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < v; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int findMin(int dist[v], bool visited[v]) {
    int min = INT_MAX;
    int minIdx = -1;

    for(int i = 0; i < v; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            minIdx = i;
        }
    }

    return minIdx;
}

void dijkstra(int graph[v][v], int src) {

    bool visited[v];
    int dist[v];

    // initialize visited to false and dist to max
    for(int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    // start with source
    // visited[src] = ;
    dist[src] = 0;

    for(int i = 0; i < v; i++) {
        int u = findMin(dist, visited);

        visited[u] = true;
        
        for(int j = 0; j < v; j++) {
            if(graph[u][j] && !visited[j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printSolution(dist);
}

int main() {

    // int graph[v][v] = {
    //     {0, 10, 5, 0, 0},
    //     {0, 0, 2, 0, 1},
    //     {0, 3, 0, 2, 9},
    //     {7, 0, 0, 0, 4},
    //     {0, 0, 0, 6, 0}
    // };
    int graph[v][v] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };
    
    dijkstra(graph, 0); // Starting from node 0

    return 0;
}