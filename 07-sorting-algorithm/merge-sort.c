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


int count = 0 ;


// merge procedure
void merge(int A[], int low, int mid, int high)
{   

    count+=1;

    int* B = (int*) malloc(sizeof(int)*(high - low + 1));
    int i, j, k;
    i = low;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    // copy elements of B in A
    i = low ;
    for (int x = 0; x < (high - low + 1); x++)
    {
        A[i] = B[x] ;
        i++;
    }

    free(B) ;
}



// recursive merge sort
void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}



int main()
{
    int n = 8;
    int arr[] = {9, 6, 2, 5, 10, 29, 14, 11};

    mergeSort(arr, 0, 7);

    printArray(arr, n);

    printf("\nnumber of merge = %d \n", count);

    return 0;
}








