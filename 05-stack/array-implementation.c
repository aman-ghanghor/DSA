#include <stdio.h>
#include <stdlib.h>

// STACK ARRAY IMPLEMENTATION
struct Stack {
    int size;
    int top;
    int* arr ;
};

// TRAVERSE 
void traverse(struct Stack* stack) {
    int i = stack->top ;
    while(i!= -1) {
        printf("%d\n", stack->arr[i]);
        i--;
    }
} 

// EMPTY
int isEmpty(struct Stack* stack) {
    if(stack->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

// FULL 
int isFull(struct Stack* stack) {
    if(stack->top == stack->size - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

// PUSH 
void push(struct Stack* stack, int data) {
    if(!isFull(stack)) {
        stack->top = stack->top + 1;
        stack->arr[stack->top] = data ;
    }
    else {
        printf("stack is full!!\n") ;
    }
}

// POP 
void pop(struct Stack* stack) {
    if(!isEmpty(stack)) {
        stack->top = stack->top - 1;
    }
    else {
        printf("stack is empty!!\n");
    }
}

// STACK TOP
int stackTop(struct Stack* stack) {
    if(!isEmpty(stack)) {
        return stack->arr[stack->top] ;
    }
    else {
        printf("stack is empty!!\n");
    }
}

// STACK BOTTOM 
int stackBottom(struct Stack* stack) {
    if(!isEmpty(stack)) {
        int i = stack->top;
        while(i != 0) {
            i--;
        }
        return stack->arr[i] ;
    }
    else {
        printf("stack is empty!!\n");
    }
}


// PEEK
int peek(struct Stack* stack, int position) {
    int arrIndex = stack->top - position + 1 ;
    if(arrIndex >= 0) {
        int value = stack->arr[arrIndex] ;
        return value ;
    }
    else {
        printf("Invalid position\n") ;
    }
}



int main() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)) ;
    stack->size = 100;
    stack->top = -1 ;
    stack->arr = (int*) malloc(sizeof(stack->size)) ;

    // PUSHING ELEMENT IN ARRAY
    push(stack, 5);
    push(stack, 9);
    push(stack, 12);
    push(stack, 3) ;
    push(stack, 2);
    printf("AFTER PUSHING :\n");
    traverse(stack) ;


    // POP
    printf("AFTER POPPING :\n");
    pop(stack);
    traverse(stack);


    // STACK TOP
    printf("STACK TOP : %d \n", stackTop(stack));


    // STACK BOTTOM
    printf("STACK BOTTOM : %d \n", stackBottom(stack));

    
    // PEEK
    printf("PEEK ITEM: %d\n", peek(stack, 2)) ;



    return 0;
}