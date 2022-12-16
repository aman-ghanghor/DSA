#include <stdio.h>
#include <stdlib.h>

int v = 6;


// Initialise matrix to 0
void init(int m[][v]) {
    int i, j;
    for(i= 0; i < v; i++) {
        for(j=0; j < v; j++) {
            m[i][j] = 0;
        }
    }
}

// Add edges
void addEdge(int m[][v], int i, int j) {
    m[i][j] = 1;
    m[j][i] = 1;
}

// Remove edge 
void removeEdge(int m[][v], int i, int j) {
    m[i][j] = 0;
    m[j][i] = 0;
}

// check if from vertex i to j edge exists or not
int edgeExists(int m[][v], int i, int j) {
    return m[i][j];
}


// print the matrix
void printMatrix(int m[][v]) {
    for(int i= 0; i < v; i++) {
      printf("i = %d \n", i);
      for(int j=0; j < v; j++) {
        printf("m[%d][%d] = %d \n", i, j, m[i][j]);
      }
    }
}



int main() {
   int matrix[v][v] ;

   init(matrix);

   addEdge(matrix, 0, 5);
   addEdge(matrix, 1, 5);
   addEdge(matrix, 2, 3);
   addEdge(matrix, 3, 4);
   addEdge(matrix, 5, 3);

   int i = 2; 
   int j = 0;
   printf("m[%d][%d] exists: ", i, j);
   if(edgeExists(matrix, i, j)) {
     printf("yes") ;
   }
   else {
     printf("No");
   }


    return 0;
}

