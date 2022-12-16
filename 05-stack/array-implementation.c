#include <stdio.h>
#include <stdlib.h>

// ======= STACK ARRAY IMPLEMENTATION =======

struct Stack {
    int size;
    int top;
    int* arr;
} ;

// Is Empty
int isEmpty(struct Stack* s) {
    if(s->top == -1) {
        return 1;
    }
    return 0;
}

// Is Full
int isFull(struct Stack* s) {
    if(s->top == s->size - 1) {
        return 1;
    }
    return 0;
}

// Traverse
void traverse(struct Stack* s) {
    if(!isEmpty(s)) {
        for(int i=s->top; i >= 0; i--) {
            printf("%d \n", s->arr[i]);
        }
    }
    else {
        printf("Stack is empty !!\n");
    }
}

// Push
void push(struct Stack* s, int data) {
    if(!isFull(s)) {
        s->top = s->top + 1;
        s->arr[s->top] = data;
    }
    else {
        printf("Stack is full !!\n");
    }
}

// Pop
int pop(struct Stack* s) {
    if(!isEmpty(s)) {
        int item = s->arr[s->top];
        s->top = s->top - 1;
        return item;
    }
    else {
        printf("Stack is empty !!\n");
    }
}

// Peek
int peek(struct Stack* s, int position) {   // position from top
    if(!isEmpty(s)) {
        int peekIndex = s->top - position + 1;
        return s->arr[peekIndex];
    }
    else {
        printf("Stack is empty !!\n");
    }
}

// Stack Top 
int stackTop(struct Stack* s) {   // position from top
    if(!isEmpty(s)) {
        return s->arr[s->top];
    }
    else {
        printf("Stack is empty !!\n");
    }
}

// Stack Bottom
int stackBottom(struct Stack* s) {   // position from top
    if(!isEmpty(s)) {
        return s->arr[0];
    }
    else {
        printf("Stack is empty !!\n");
    }
}




int main() {
    int n = 100;
    struct Stack * stack = (struct Stack*) malloc(sizeof(struct Stack)) ;
    stack->size = n;
    stack->arr = (int*) malloc(n*sizeof(int));
    stack->top = -1;
    
    // IS EMPTY
    if(isEmpty(stack)) {
        printf("Stack is empty !!\n");
    }
    
    // IS FULL
    if(isFull(stack)) {
        printf("Stack is full !!\n");
    }
    
    // PUSH
    push(stack, 2);
    push(stack, 3);
    push(stack, 5);
    push(stack, 8);
    push(stack, 14);
    push(stack, 20);
    
    printf("After push: \n");
    traverse(stack);
    
    // POP
    printf("\nPopped item: %d \n", pop(stack));
    printf("After pop: \n");
    traverse(stack);
    
    // PEEK
    printf("\nPeeked item: %d \n", peek(stack, 3));
    printf("After peek: \n");
    traverse(stack);
    
    // STACK TOP
    printf("\nStack top: %d \n", stackTop(stack));
    
    // STACK Bottom
    printf("\nStack top: %d \n", stackBottom(stack));
 

    return 0;
}