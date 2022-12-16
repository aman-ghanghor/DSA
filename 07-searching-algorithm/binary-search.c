#include <stdio.h>
#include <stdlib.h>

// how many time binarySearch function run
int count = 0;


// Binary Search
int binarySearch(int A[], int start, int end, int value) {
    count++;
    int mid = (start + end) / 2 ;

    if(value == A[mid]) {
        return mid;
    }
    else if(value < A[mid]) {
        binarySearch(A, start, mid - 1, value);
    }
    else {
        binarySearch(A, mid + 1, end, value);
    }
}


int main() {
    int n = 6;
    int arr[] = {3, 5, 9, 15, 16, 50, 53};

    int index = binarySearch(arr, 0, 6, 9);
    printf("Search Index = %d \n", index);

    printf("binarySearch Run count = %d", count);

    return 1;
}