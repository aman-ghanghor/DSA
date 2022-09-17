#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int* arr;
};


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
int isFull(struct Queue* queue) {
    if(queue->r == queue->size - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

// TRAVERSE
void traverse(struct Queue* queue) {
    if(!isEmpty(queue)) {
        for(int i=queue->f+1; i <= queue->r; i++) {
            printf("%d \n", queue->arr[i]);
        }
    }
    else {
        printf("queue is empty!!\n");
    }
}

// ENQUEUE
void enqueue(struct Queue* queue, int data) {
    if(!isFull(queue)) {
        queue->r = queue->r + 1;
        queue->arr[queue->r] = data;
    }
    else {
        printf("queue is full!!\n");
    }
}

// DEQUEUE 
void dequeue(struct Queue* queue) {
    if(!isEmpty(queue)) {
        queue->f = queue->f + 1;
    }
    else {
        printf("queue is empty!!\n");
    }
}

// PEEK AT POSITION number
int peek(struct Queue* queue, int position) {
    if(!isEmpty(queue)) {
        int count = 1;
        for(int i=queue->f+1; i <= queue->r; i++) {
            if(count==position) {
                return queue->arr[i];
            }
            count++;
        }
    }
    else {
        printf("queue is empty!!\n");
    }
}





int main() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->size = 20;
    queue->f = queue->r = -1;
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
    printf("PEEK ITEM = %d \n", peek(queue, 3));


    return 0; 
}