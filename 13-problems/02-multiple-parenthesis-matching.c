#include <stdio.h>
#include <stdlib.h>

// ---------------- MULTIPLE PARENTHESIS MATCHING PROBLEM -----------------


struct Stack {
    int size;
    int top;
    char* arr ;
};

// TRAVERSE 
void traverse(struct Stack* stack) {
    int i = stack->top ;
    while(i!= -1) {
        printf("%c\n", stack->arr[i]);
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
void push(struct Stack* stack, char data) {
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
char stackTop(struct Stack* stack) {
    if(!isEmpty(stack)) {
        return stack->arr[stack->top] ;
    }
    else {
        printf("stack is empty!!\n");
    }
}


int isBalanced(char exp[]) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)) ;
    stack->size = 100;
    stack->top = -1 ;
    stack->arr = (char*) malloc(sizeof(stack->size)) ;

    int i = 0;
    while(exp[i] != '\0') {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') {
            push(stack, exp[i]);
        }
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']') {
            if(isEmpty(stack)) {
                return 0;
            }
            else {
                int l = stackTop(stack);
                int c = exp[i];
                if((c==')' && l=='(') || (c=='}' && l=='{') || (c==']' && l=='[')) {
                    pop(stack);
                }
                else {
                    return 0;
                }
            }
        }
        i++;
    }

    if(isEmpty(stack)) {
        return 1;
    }
    else {
        return 0;
    }
}


int main() {
    char exp[] = "{{a+[b-(c/d)]*e}-f}";

    if(isBalanced(exp)) {
        printf("Balanced expression\n");
    }
    else {
        printf("Unbalanced expression\n");
    }
    
   

    return 0;
}