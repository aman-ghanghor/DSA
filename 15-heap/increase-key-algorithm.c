#include <stdio.h>
#include <stdbool.h>

int N ;

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


// update key : increase key algorithm
void increase_key(int arr[], int i, int key) {
    if(key > arr[i]) {
        arr[i] = key;
        while(i > 0 && arr[i] > arr[i/2]) {
            swap(arr, i, i/2);
            i = i / 2;
        }
    }
}


int main() {
    // heap array : (max-heap => descending order array)
    int arr[N] = {15, 12, 8, 7, 5, 4, 2};

    // index to update - 4
    // key - 18 ( 5 to 18)
    int i = 3;
    int key = 18;

    // increase key
    increase_key(arr, i, key);

    // print heap
    printHeap(arr, N);
    

    return 0;
}