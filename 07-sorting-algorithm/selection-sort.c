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


void selectionSort(int A[], int n) {
    for(int i=0; i < n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j < n; j++) {
            if(A[j] < A[minIndex]) {
            minIndex = j ;
            }
        }
        int temp = A[i] ;
        A[i] = A[minIndex] ;
        A[minIndex] = temp ;
    }
}


int main() {
    int n = 6 ;
    int arr[] = {9, 6, 5, 3, 14, 11} ;

    selectionSort(arr, n) ;
    printArray(arr, n) ;
    
    return 0 ;
}

