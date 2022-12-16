#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define n 6


int minWeightVertex(int distance[], bool mst[]) {
    int min = INT_MAX;
    int min_index ;
    for(int i=0; i < n; i++) {
        // not in mst and weight greater than min
        if(mst[i]==false && distance[i] < min) {
            min = distance[i];
            min_index = i;
        }
    }

    return min_index;
}


void printMST(int parent[], int graph[n][n]) {
    for(int i=1; i < n; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}


void findMST(int graph[n][n]) {
    // contain vertices
    bool mst[n];
    // track parent of vertices
    int parent[n];
    // use for edge relaxation
    int distance[n];

    for(int i=0; i < n; i++) {
        distance[i] = INT_MAX;
        mst[i] = false;
    }

    // add source vertex to mst
    parent[0] = -1;  // first vertex is root of graph always
    distance[0] = 0; 

    // Iterate (v-1) times, mst contain (v-1) edges
    for(int i=0; i < (n-1); i++) {
        
        // 1. find min weight edge vertex
        int u = minWeightVertex(distance, mst);

        // 2. add it to mst
        mst[u] = true;

        // 3. relax adjacent vertex
        for(int v=0; v < n; v++) {

            // graph[u][j] = edge exists
            // mst[j]==false , means vertex is not in mst

            if(graph[u][v] && mst[v]==false && graph[u][v] < distance[v]) {
                distance[v] = graph[u][v];
                parent[v] = u ;
            }

        }
    
    }
    
    printMST(parent, graph);

}


int main() {

    int graph[n][n] = {
        {0, 4, 6, 0, 0, 0},
        {4, 0, 6, 3, 4, 0},
        {6, 6, 0, 1, 0, 0},
        {0, 3, 1, 0, 2, 3},
        {0, 4, 0, 2, 0, 7},
        {0, 0, 0, 3, 7, 0}
    };

    
    findMST(graph);




    return 1;
}