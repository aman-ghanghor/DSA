#include <stdio.h>
#include <stdlib.h>

// =================== Breadth First Search (BFS) Algorithm ====================

// QUEUE CIRCULAR ARRAY IMPLEMENTATION

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int size = 10;
// circular increment
int cinc(int n)
{
    int result = (n + 1) % size;
    return result;
}
// circular decrement
int cdec(int n)
{
    int result = (n - 1) % size;
    return result;
}

// IS EMPTY
int isEmpty(struct Queue *queue)
{
    if (queue->f == queue->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// IS FULL
int isFull(struct Queue *q)
{
    if (cinc(q->r) == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// TRAVERSE
void traverse(struct Queue *q)
{
    if (!isEmpty(q))
    {
        int i = cinc(q->f);
        int R = cinc(q->r);
        while (i != R)
        {
            printf("%d \n", q->arr[i]);
            i = cinc(i);
        }
    }
    else
    {
        printf("queue is empty!!\n");
    }
}

// ENQUEUE
void enqueue(struct Queue *q, int data)
{
    if (!isFull(q))
    {
        q->r = cinc(q->r);
        q->arr[q->r] = data;
    }
    else
    {
        printf("queue is full!!\n");
    }
}

// DEQUEUE
int dequeue(struct Queue *q)
{
    if (!isEmpty(q))
    {
        int x =  q->arr[q->f + 1] ;
        q->f = cinc(q->f);
        return x ;
    }
    else
    {
        printf("queue is empty!!\n");
    }
}

// PEEK AT POSITION number
int peek(struct Queue *q, int position)
{
    if (!isEmpty(q))
    {
        printf("PEEKING...\n");
        int count = 1;
        int i = cinc(q->f);
        int R = cinc(q->r);
        while (i != R)
        {
            if (count == position)
            {
                return q->arr[i];
            }
            count++;
            i = cinc(i);
        }
    }
    else
    {
        printf("queue is empty!!\n");
    }
}

int main()
{
    // Initializing Queue (circular array implementation)
    struct Queue* q;              // exploration queue
    q->size = 400;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    // BFS Implementation
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0}; // contain visited element
    /*****************************
         0 ------- 1
         |  \      |
         |    \    |
         |      \  |
         2 ------- 3
          \       /
           \     /
            \   /
              4
            /   \
           /     \
          /       \
         5         6

    ******************************/
    int graph[7][7] = {               
                     {0, 1, 1, 1, 0, 0, 0},
                     {1, 0, 0, 1, 0, 0, 0},
                     {1, 0, 0, 1, 1, 0, 0},
                     {1, 1, 1, 0, 1, 0, 0},
                     {0, 0, 1, 1, 0, 1, 1},
                     {0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0}};

    visited[i] = 1 ;   // visit 0

    // enqueue 0 for exploration
    enqueue(q, i);   //

    while(!isEmpty(q)) {
        int node = dequeue(q);     

        // explore node 
        for(int j=0; j < 7; j++) {
           if(graph[node][j] == 1 && visited[j] == 0) {    // visited[j] == 0 means j is not visited
              printf("%d ", j);        
              visited[j] = 1;  // j is now visited
              enqueue(q, j);   // enqueue j for exploration
           }
        }

    }

    printf("\n%d ", visited[3]);


    return 0;
}