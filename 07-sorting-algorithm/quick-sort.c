#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int n)
{
    printf("{");
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d", A[i]);
        }
        else
        {
            printf("%d, ", A[i]);
        }
    }
    printf("}");
}

int partition(int A[], int low, int high)
{
    int pivot, i, j, temp;
    pivot = A[low];
    i = low + 1;
    j = high;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if( i < j) {
            temp = A[i] ;
            A[i] = A[j] ;
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j] ;
    A[j] = temp;

    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // sort left subarray
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    int arr[] = {19, 7, 5, 11, 16, 48, 2, 4};

    quickSort(arr, 0, 7);
    printArray(arr, 8);

    return 0;
}
