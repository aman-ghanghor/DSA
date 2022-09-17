#include <stdio.h>
#include <stdlib.h>


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


int maximum(int A[], int n) {
    int max = A[0] ;
    for(int i=1; i < n ; i++) {
        if(A[i] > max) {
            max = A[i] ;
        }
    }
    return max;
}



void countSort(int A[], int n) {
    int max = maximum(A, n) ;
    int* count = (int*) malloc(sizeof(int)*(max+1)) ;
    // initialise count array with 0
    for(int i=0; i < max+1; i++) {
        count[i] = 0 ;
    }
    // traverse through array A
    for(int i=0; i < n; i++) {
        count[A[i]] = count[A[i]] + 1 ;
    }

    int i, j;
    i=j=0;

    while(i < max+1) {
        if(count[i]==0) {
           i++;
        }
        else {
           A[j] = i ;
           j++;
           count[i] = count[i] - 1;
        }
    }
}


int main() {
    int n = 6 ;
    int arr[] = {19, 3, 1, 10, 7, 11} ;

    countSort(arr, n);
    printArray(arr, n);
    
    return 0 ;
}




