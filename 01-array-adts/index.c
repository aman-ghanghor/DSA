#include <stdio.h>
#include <stdlib.h>

struct Array {
    int total_size;
    int used_size;
    int* ptr ;
};


int main() {
    struct Array arr;
    arr.total_size = 5;
    arr.ptr = (int*) malloc(sizeof(int)*(arr.total_size)) ;

    // take user input
    for(int i=0; i < arr.total_size; i++) {
        int num ;
        printf("Enter the number: ") ;
        scanf("%d", &num);
        arr.ptr[i] = num;
    }

    printf("ARRAY ELEMENTS:\n") ;

    for(int i=0; i < arr.total_size; i++) {
        printf("%d \n", arr.ptr[i]) ;
    }

    return 0 ;
}













