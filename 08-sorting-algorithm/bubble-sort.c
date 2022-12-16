#include <stdio.h>


void printArray(int A[], int n) {
    printf("{") ;
    for(int i=0; i < n; i++) {
       if(i==n-1) {
          printf("%d", A[i]) ;
       }
       else {
          printf("%d, ", A[i]) ;
       }
    }
    printf("}") ;
}


void bubbleSort(int A[], int n) {
    int temp, isSorted;
    isSorted = 0;
    for(int i=0; i < n - 1; i++) {
        isSorted = 1; 
        for(int j=0; j < (n-1-i); j++) {
           if(A[j+1] < A[j]) {
              temp = A[j] ;
              A[j] = A[j+1] ;
              A[j+1] = temp ;
              isSorted = 0 ;
           }
        }
        if(isSorted) {
           return ;
        }
    }
}


int main() {
    int n = 6 ;
    int arr[] = {2, 2, 5, 7, 11, 11} ;

    bubbleSort(arr, n) ;
    printArray(arr, n) ;
    
    return 0 ;
}