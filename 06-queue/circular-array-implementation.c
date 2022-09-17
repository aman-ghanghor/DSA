#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int* arr;
};


int size = 10;
// circular increment
int cinc(int n) {
    int result = (n + 1) % size;
    return result;
}
// circular decrement
int cdec(int n) {
    int result = (n -1) % size;
    return result;
}


// IS EMPTY
int isEmpty(struct Queue* queue) {
    if(queue->f == queue->r) {
        return 1;
    }
    else {
        return 0;
    }
}

// IS FULL
int isFull(struct Queue* q) {
    if( cinc(q->r) == q->f ) {
        return 1;
    }
    else {
        return 0;
    }
}

// TRAVERSE
void traverse(struct Queue* q) {
    if(!isEmpty(q)) {
        int i = cinc(q->f) ;
        int R = cinc(q->r);
        while(i != R ) {
            printf("%d \n", q->arr[i]) ;
            i = cinc(i) ;
        }
    }
    else {
        printf("queue is empty!!\n");
    }
}

// ENQUEUE
void enqueue(struct Queue* q, int data) {
    if(!isFull(q)) {
        q->r = cinc(q->r) ;
        q->arr[q->r] = data;
    }
    else {
        printf("queue is full!!\n");
    }
}

// DEQUEUE 
void dequeue(struct Queue* q) {
    if(!isEmpty(q)) {
        q->f = cinc(q->f) ;
    }
    else {
        printf("queue is empty!!\n");
    }
}

// PEEK AT POSITION number
int peek(struct Queue* q, int position) {
    if(!isEmpty(q)) {
        printf("PEEKING...\n");
        int count = 1;
        int i = cinc(q->f);
        int R = cinc(q->r);
        while(i != R) {
            if(count==position) {
                return q->arr[i];
            }
            count++;
            i = cinc(i);
        }
    }
    else {
        printf("queue is empty!!\n");
    }
}




int main() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->size = 10;
    queue->f = queue->r = queue->size - 1;
    queue->arr = (int*) malloc(queue->size*sizeof(int));

    // ENQUEUE
    enqueue(queue, 3);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 9);
    enqueue(queue, 12);
    printf("AFTER ENQUEUE :\n");
    traverse(queue);

    // DEQUEUE
    dequeue(queue);
    printf("AFTER DEQUEUE :\n");
    traverse(queue);

    // PEEK
    printf("PEEK ITEM = %d \n", peek(queue, 5));


    return 0; 
}

