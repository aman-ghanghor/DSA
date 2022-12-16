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


void insertionSort(int A[], int n) {
    int key;
    for(int i=1; i <= n-1; i++) {
        key = A[i];
        int j = i-1;
        while(A[j] > key) {
           A[j+1] = A[j] ;
           j--;
           if(j < 0) {
             break;
           }
        }
        A[j+1] = key;
    }
}


int main() {
    int n = 9 ;
    int arr[] = {9, 6, 1000, 5, 14, 292, 13, 2, 11} ;

    insertionSort(arr, n);
    printArray(arr, n);
    
    return 0 ;
}






