#include <stdio.h>
#include <stdlib.h>



// =========== ARRAY ADT ============

struct Array {
    int total_size;
    int used_size;
    int * ptr;
} ;


// ----- Operations -----


// traverse 
void traverse(struct Array* a) {
  for(int i=0; i < a->used_size ; i++) {
     printf("%d \n", a->ptr[i]);
  }
}

// push 
void push(struct Array* a, int value) {
    a->used_size = a->used_size + 1;
    a->ptr[a->used_size - 1] = value;
}

// pop
int pop(struct Array* a) {
    int popped = a->ptr[a->used_size - 1] ;
    a->used_size = a->used_size - 1;
    return popped;
}

// at - return item at the index
int at(struct Array* a, int index) {
    if(index > a->used_size - 1) {
        return 0;
    }
    else {
        return a->ptr[index];
    }
}

// update at index
void update(struct Array* a, int index, int value) {
    if(index < (a->used_size)) {
       a->ptr[index] = value ;
    }
}

// remove from index
int delete(struct Array* a, int index) {
    int temp = a->ptr[index];
    int i = index;
    int x = index + 1;
    
    if(index > (a->used_size - 1)) {
        return 0;
    }
    if(index == (a->used_size - 1)) {
        return pop(a);
    }
    
    while(x < (a->used_size)) {
        a->ptr[i] = a->ptr[x] ;
        i++;
        x++;
    }
    
    a->used_size = a->used_size - 1;
    return temp;
}







int main() {
  struct Array* arr = (struct Array*) malloc(sizeof(struct Array)) ;
  arr->total_size = 10;
  arr->used_size = 0;
  arr->ptr = (int *) malloc((arr->total_size) * sizeof(int)) ;
  
  push(arr, 3);
  push(arr, 9);
  push(arr, 6);
  push(arr, 23);
  push(arr, 11);
  push(arr, 15);
  push(arr, 40);
  
  printf("After Pushing elements :- \n") ;
  
  for(int i=0; i < arr->used_size ; i++) {
      printf("%d \n", arr->ptr[i]);
  }
  
  // :
  // :
  // :
  // :
  
  printf("\nPopped : %d", pop(arr)) ;
  printf("\nPopped : %d", pop(arr)) ;
  
  printf("\n\nAfter Popping elements :- \n") ;
  
  for(int i=0; i < arr->used_size ; i++) {
      printf("%d \n", arr->ptr[i]);
  }
 
  // :
  // :
  // :
  // :
  
  int index1 = 2 ;
  printf("\n\nElement at index %d : %d\n", index1, at(arr, index1));
  
  // :
  // :
  // :
  // :
  
  int index2 = 1;
  printf("\nremove from index %d : %d \n", index2, delete(arr, index2));
  printf("After remove from index %d :- \n", index2);
  
  for(int i=0; i < arr->used_size ; i++) {
    printf("%d \n", arr->ptr[i]);
  }
  
  // :
  // :
  // :
  // :
  
  int index3 = 2 ;
  printf("\nUpdate at index %d\n", index3) ;
  update(arr, index3, 13);
  printf("After update at index %d\n", index3);
  traverse(arr);
  
 
  
}


