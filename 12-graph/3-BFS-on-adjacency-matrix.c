#include <stdio.h>
#include <stdlib.h>

int v = 7;

// =================== Breadth First Search (BFS) Algorithm ====================

// QUEUE CIRCULAR ARRAY IMPLEMENTATION

struct Queue {
    int size;
    int f;
    int r;
    int *arr;
};

int size = 10;
// circular increment
int cinc(int n) {
    int result = (n + 1) % size;
    return result;
}
// circular decrement
int cdec(int n) {
    int result = (n - 1) % size;
    return result;
}

// CREATE QUEUE
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->size = size;
    q->f = q->r = 0;
    q->arr = (int *)malloc(size * sizeof(int));

    return q;
}

// IS EMPTY
int isEmpty(struct Queue *queue) {
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
int isFull(struct Queue *q) {
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
void traverse(struct Queue *q) {
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
void enqueue(struct Queue *q, int data) {
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
int dequeue(struct Queue *q) {
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
int peek(struct Queue *q, int position) {
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


// BFS traversal
void bfs(int graph[][v], int startedVertex) {
    // exploration queue - contain vertex which need to be explored
    struct Queue* q = createQueue(100);

    // contain visited element
    int visited[7] = {0, 0, 0, 0, 0, 0, 0}; 

    // contain distance of vertex from source vertex
    int distance[7] = {0, 0, 0, 0, 0, 0, 0};

    int i = startedVertex;
    int d = 0;      // initial distance

    printf("%d, ", i);

    enqueue(q, i);
    visited[i] = 1;
    distance[i] = 0;

    while(!isEmpty(q)) {
        int node = dequeue(q);

        for(int j=0; j < v; j++) {
            // if vertex j exist and it is not visited
            if(graph[node][j] == 1 && visited[j] == 0) { 
                // traversed
                printf("%d, ", j);

                // now it is visited
                visited[j] = 1;   

                // distance from source
                distance[j] = distance[node] + 1;

                // insert in exploration queue
                enqueue(q, j);      
            }
        }

    }


    // -------- ------- --------
    printf("\nDistance array: \n");
    for(int i=0; i < 7; i++) {
        printf("%d \n", distance[i]);
    }

}




int main(){
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
                        {0, 0, 0, 0, 1, 0, 0},
                    };

    // bfs(graph, 2);

    return 0;
}


