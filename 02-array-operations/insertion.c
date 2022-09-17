#include <stdio.h>
#include <stdlib.h>

void traverse(int A[], int size) {
   for(int i=0; i < size; i++) {
      printf("%d \n", A[i]) ;
   }
}


int insert(int A[], int size, int capacity, int element, int index) {
    if(size >= capacity) {
        printf("Array is full!! \n") ;
    }
    else {
        for(int i=size-1; i >= index; i--) {
            A[i+1] = A[i] ;
        }
        A[index] = element ;
        return size + 1;
    }
}


int main() {
    int capacity = 100;
    int size = 3;
    int arr[100] = {3, 5, 7} ;

    size = insert(arr, size, capacity, 23, 2) ;
    traverse(arr, size);
    printf("\n") ;
    size = insert(arr, size, capacity, 11, 0) ;
    traverse(arr, size);


    return 0;
}