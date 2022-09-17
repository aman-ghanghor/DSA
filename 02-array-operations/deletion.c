#include <stdio.h>
#include <stdlib.h>

void traverse(int A[], int size) {
   for(int i=0; i < size; i++) {
      printf("%d \n", A[i]) ;
   }
}


int delete(int A[], int size, int capacity, int index) {
    for(int i=index +1; i <= size; i++) {
        A[i-1] = A[i];
    }
    return size - 1;
}


int main() {
    int capacity = 100;
    int size = 6 ;
    int arr[100] = {3, 5, 7, 8, 29, 50} ;

    size = delete(arr, size, capacity, 2) ;
    traverse(arr, size);

    return 0;
}