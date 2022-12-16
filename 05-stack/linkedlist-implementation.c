#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// EMPTY
int isEmpty(struct Node* top) {
    if(top==NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// FULL
int isFull(struct Node* top) {
    struct Node* p = (struct Node*) malloc(sizeof(struct Node)) ;
    if(p==NULL) {
        return 1 ;
    }
    else {
        return 0;
    }
}


// TRAVERSE
void traverse(struct Node* ptr) {
   if(!isEmpty(ptr)) {
      while(ptr!=NULL) {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
      }
   }
   else {
       printf("stack is empty!!");
   }
}


// PUSH
struct Node* push(struct Node* top, int data) {
    if(!isFull(top)) { // when not full
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
    else {
        printf("stack is full!!\n");
    }
}

// POP
struct Node* pop(struct Node* top) {
    if(!isEmpty(top)) {
        struct Node* ptr = top;
        top = top->next;
        free(ptr);
        return top;
    }
    else {
        printf("stack is empty!!\n");
    }
}


// PEEK
int peek(struct Node* top, int position) {
    if(!isEmpty(top)) {
       struct Node* ptr = top;
       int i=1;
       while(ptr!=NULL) {
          if(i==position) {
            return ptr->data;
          }
          ptr = ptr->next;
          i++;
       }
    }
    else {
       printf("stack is empty!!\n");
    }
}

// STACK TOP
int stackTop(struct Node* top) {
    if(isEmpty(top)) {
       printf("Stack is empty !!\n");
    }
    else {
        return top->data;
    }
}

// STACK BOTTOM
int stackBottom(struct Node* top) {
    if(isEmpty(top)) {
       printf("Stack is empty !!\n");
    }
    else {
        struct Node* ptr = top;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        return ptr->data;
    }
}



int main() {
    struct Node* top = NULL;

    // PUSH
    top = push(top, 5);
    top = push(top, 9);
    top = push(top, 10);
    top = push(top, 11);
    top = push(top, 16);
    printf("AFTER PUSHING : \n");
    traverse(top);

    // POP
    top = pop(top);
    printf("AFTER POPPING : \n");
    traverse(top);

    // PEEK
    printf("PEEK ITEM = %d\n", peek(top, 2));


    return 0;
}

