#include <stdio.h>
#include <stdbool.h>

int N = 7 ;

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


// update key : decrease key algorithm
void decrease_key(int arr[], int i, int key) {
    if(key < arr[i]) {
        arr[i] = key;
        heapify(arr, N, i);
    }
}


int main() {
    // heap array : (max-heap => descending order array)
    int arr[7] = {15, 12, 8, 7, 5, 4, 2};

    // index to update - 1
    // key - 3 ( 12 to 3)
    int i = 1;
    int key = 3;

    // increase key
    decrease_key(arr, i, key);

    // print heap
    printHeap(arr, N);
    

    return 0;
}