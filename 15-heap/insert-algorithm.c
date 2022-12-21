#include <stdio.h>
#include <stdbool.h>

int N = 7;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// heapify algorithm
void heapify(int arr[], int N, int i) {
    int l = (i*2 + 1);
    int r = (i*2 + 2);
    int largest = i;

    if(l < N && arr[l] > arr[largest]) {
        largest = l;
    }

    if(r < N &&  arr[r] > arr[largest]) {
        largest = r;
    }

    if(largest != i) {
        swap(arr, i, largest);
        heapify(arr, N, largest);
    }
}

void printHeap(int arr[], int N) {
    for(int i=0; i < N; i++) {
        printf("%d, ", arr[i]);
    }
}


// insert algorithm
void insert(int A[], int value) {
    N = N + 1;
    A[N-1] = value;
    int i = N - 1;

    // percolate up
    while(i > 0 && A[i] > A[i/2]) {
        swap(A, i, i/2);
        i = i / 2;
    }
}



int main() {
    // heap array : (max-heap => descending order array)
    int arr[7] = {14, 12, 8, 7, 5, 4, 2};

    // insert
    int value = 9;
    insert(arr, value);

    // print heap
    printHeap(arr, N);

    return 0;
}