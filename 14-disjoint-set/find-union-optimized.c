#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 7
#define E 6

typedef struct Nodes {
    int parent;
    int rank;
} Node;

Node parentSet[V];

// find operation / find absolute root
int find(int x) {
    if(parentSet[x].parent == -1) {
        return x;
    }
    return parentSet[x].parent = find(parentSet[x].parent);
}

// check if cycle is formed or not
bool is_cycle(int a, int b) {
    // absolute root of a and b
    int rootA = find(a);
    int rootB = find(b);
    // a, b in same set
    if(rootA == rootB) {
        return true;
    }
    else {
        return false;
    }
}

// union by rank
void unionOperation(int from, int to) {
    if(is_cycle(from, to) == false) {
        int fromP = find(from);
        int toP = find(to);
        
        if(parentSet[fromP].rank == parentSet[toP].rank) {
            parentSet[fromP].parent = toP ;
            parentSet[toP].rank += 1;
        }
        else if (parentSet[fromP].rank < parentSet[toP].rank) {
            parentSet[fromP].parent = toP ;
        }
        else {
            parentSet[toP].parent = fromP ;
        }
    }
} 

int main() {
    // initialize parentSet
    for(int i=0; i < V; i++) {
        parentSet[i].parent = -1;
        parentSet[i].rank = 0;
    }
    
    int edgeList[E][2] = {
        {0, 1},
        {0, 2},
        {2, 3},
        {3, 4},
        {5, 4},
        {5, 6}
    };
    
    for(int i=0; i < E; i++) {
        unionOperation(edgeList[i][0], edgeList[i][1]);
    }
    
    // print edges
    for(int i=0; i < V; i++) {
        printf("%d -> %d \n", i, parentSet[i].parent);
    }
    
    return 1;
}
