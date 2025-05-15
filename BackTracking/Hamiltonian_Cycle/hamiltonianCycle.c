#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int x[V] = {0};  // Stores the Hamiltonian path

void nextVal(int k) {

    while(1){
        x[k] = (x[k] + 1) % (V);
        if(x[k] == 0)
            return;         // backtrack
        
        // check if x[k] and x[k-1] are connected
        if (graph[x[k - 1]][x[k]] == 0)
            continue;
        
        // check if there are no same x[]
        int j;
        for(j = 0; j < k; j++){
            if(x[j] == x[k])
                break;
        }
        if(j == k){
            // if k < num of nodes then return or else check if connected to 1st node
            if (k < V - 1 || (k == V - 1 && graph[x[k]][x[0]] == 1))
                return;
        }
    }
}

void hamiltonianCycle(int k) {

    nextVal(k);
    if(x[k] == 0)
        return;
    
    if(k == V - 1) {
        printf("Possible Answers: \n");
        for(int i = 0; i < V; i++) {
            printf("%d ", x[i]);
        }
        printf("\n");
    }
    else{
        hamiltonianCycle(k + 1);
    }
}

int main() {

    for (int i = 0; i < V; i++)
        x[i] = 0;  // initialize path to 0s

    x[0] = 0;  // Start from vertex 0
    hamiltonianCycle(1);

    return 0;
}