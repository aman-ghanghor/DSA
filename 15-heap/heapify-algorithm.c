#include <stdio.h>
#include <stdbool.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// heapify algorithm
void heapify(int arr[], int size, int i) {
    int l = (i*2 + 1);
    int r = (i*2 + 2);
    int largest = i;

    if(l < size && arr[l] > arr[largest]) {
        largest = l;
    }

    if(r < size &&  arr[r] > arr[largest]) {
        largest = r;
    }

    if(largest != i) {
        swap(arr, i, largest);
        heapify(arr, size, largest);
    }
}

void printHeap(int arr[], int size) {
    for(int i=0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
}



int main() {
    // heap size
    int size = 7;
    // heap array : (max-heap => descending order array)
    int arr[7] = {1, 12, 8, 7, 5, 4, 2};

    // apply heapify on index i
    int i = 0;

    heapify(arr, size, i);

    // print heap
    printHeap(arr, size);

    return 0;
}