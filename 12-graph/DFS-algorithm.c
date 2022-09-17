#include <stdio.h>
#include <stdlib.h>

    /*****************************
         0 ------- 1
         |  \      |
         |    \    |
         |      \  |
         2 ------- 3
          \       /
           \     /
            \   /
              4
            /   \
           /     \
          /       \
         5         6

    ******************************/

    // DFS Implementation
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0} ;
    int graph[7][7] = {               
                     {0, 1, 1, 1, 0, 0, 0},
                     {1, 0, 0, 1, 0, 0, 0},
                     {1, 0, 0, 1, 1, 0, 0},
                     {1, 1, 1, 0, 1, 0, 0},
                     {0, 0, 1, 1, 0, 1, 1},
                     {0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0}};

void DFS(int i) {
    printf("%d ", i);
    visited[i] = 1;

    for(int j=0; j < 7; j++) {
        if(graph[i][j] == 1 && visited[j] == 0 ) {
            DFS(j);
        }
    }
}


int main() {

    DFS(2) ;



    return 0 ;
}