#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* f = NULL;
struct Node* r = NULL;

// EMPTY
int isEmpty() {
    if(f==r && f==NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// FULL

// TRAVERSE
void traverse() {
    if(!isEmpty(f, r)) {
        struct Node* n = f ;
        while(n != NULL) {
            printf("%d \n", n->data);
            n = n->next;
        }
    }
    else {
        printf("queue is empty!!\n");
    }
}


// ENQUEUE
void enqueue(int data) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL) {
        printf("queue is full!!\n");
    }
    else {
       n->data = data;
       n->next = NULL;

       if(f == NULL) {
            f = r = n;
       }
       else {
            r->next = n;
            r = n;
       }
    }
}


// DEQUEUE
int dequeue() {
    if(!isEmpty(f, r)) {
        struct Node* n = f ;
        f = f->next ;
        free(n);
    }
    else {
        printf("queue is empty!!\n");
    }
}




int main() {
    // ENQUEUE
    enqueue(2);
    enqueue(4);
    enqueue(5);
    enqueue(8);
    enqueue(10);
    printf("AFTER ENQUEUE :\n");
    traverse();

    // DEQUEUE
    dequeue();
    dequeue();
    printf("AFTER DEQUEUE :\n");
    traverse();


    return 0;
}