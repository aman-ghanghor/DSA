#include <stdio.h>
#include <stdlib.h>

void traverse(int A[], int size) {
   for(int i=0; i < size; i++) {
      printf("%d \n", A[i]) ;
   }
}


void update(int A[], int element, int index) {
    A[index] = element;
}


int main() {
    int capacity = 100;
    int size = 3;
    int arr[100] = {3, 5, 7} ;

    update(arr, 50, 2) ;
    traverse(arr, size);

    return 0;
}