#include <stdio.h>
#include <stdlib.h>

// Linear Search
int linearSearch(int A[], int n, int value) {
    for(int i=0; i < n; i++) {
        if(A[i] == value) {
            return i;
        }
    }
    return 0;
}


int main() {
    int n = 10;
    int arr[] = {5, 13, 7, 32, 92, 9, 2, 16, 24, 18};

    int index = linearSearch(arr, n, 5);
    printf("Search Index = %d", index);

    return 1;
}