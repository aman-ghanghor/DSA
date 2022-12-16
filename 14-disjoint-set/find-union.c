// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#define V 7
#define E 6

int parent[V] = {-1, -1, -1, -1, -1, -1, -1} ;

// find operation / find absolute root
int find(int x) {
    if(parent[x] == -1) {
        return x;
    }
    else {
        return find(parent[x]);
    }
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

// union 
void unionOperation(int from, int to) {
    if(is_cycle(from, to) == false) {
        parent[find(from)] = find(to);
    }
}

int main() {
    int edgeList[E][2] = {
        {2, 1},
        {1, 0},
        {0, 5},
        {0, 3},
        {5, 4},
        {5, 6}
    };
    
    for(int i=0; i < E; i++) {
        unionOperation(edgeList[i][0], edgeList[i][1]);
    }
    
    // print edges
    for(int i=0; i < V; i++) {
        printf("%d -> %d \n", i, parent[i]);
    }
    
    return 1;
    
}