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

// ========= GRAPH ADJACENCY LIST =========
typedef struct N {
    int vertex;
    struct N* next;
} Node;

typedef struct G {
    // number of vertices
    int nov ;
    // a pointer which stores the (struct Node*) pointer
    Node** adjLists;        
} Graph;


// create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->nov = vertices;
    graph->adjLists = (Node**) malloc(vertices * sizeof(Node*));

    for(int i=0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// creating new node/vertex
Node* createNode(int v) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;

    return node;
}

// is edge exists from vertex a to b
int edgeExists(Graph* graph, int a, int b) {
    Node* i = graph->adjLists[a];
    while(i) {
        if(i->vertex == b) {
            return 1;
        }
        i = i->next;
    }
    
    return 0;
}

// add edge
void addEdge(Graph* graph, int s, int d) {
    // if edge already not exists
    if(!edgeExists(graph, s, d)) {
        // add edge from s to d
        Node* newNode = createNode(d);
        newNode->next = graph->adjLists[s];
        graph->adjLists[s] = newNode;

        // add edge from d to s
        newNode = createNode(s);
        newNode->next = graph->adjLists[d];
        graph->adjLists[d] = newNode;
    }
    else {
        printf("Edge %d---%d already exists\n", s, d);
    }
}


// print graph 
void printGraph(Graph* graph) {
    for(int i=0; i < graph->nov; i++) {
        Node* temp = graph->adjLists[i];
        printf("vertex: %d \n", i);
        while(temp) {
            printf("%d \n", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}


// BFS traversal
void bfs(Graph* graph, int startedVertex) {
    // exploration queue - contain vertex which need to be explored
    struct Queue* q = createQueue(100);

    // contain visited element
    int visited[7] = {0, 0, 0, 0, 0, 0, 0}; 

    // contain distance of vertex from source vertex
    int distance[7] = {0, 0, 0, 0, 0, 0, 0} ;

    int i = startedVertex;
    int d = 0;      // initial distance

    visited[i] = 1;
    distance[i] = 0;
    enqueue(q, i);

    printf("BFS Traversal: \n");
    printf("%d, ", i);

    while(!isEmpty(q)) {
        int node = dequeue(q);

        for(int j=0; j < v; j++) {
            // if vertex j exist and it is not visited
            if(edgeExists(graph, node, j) && visited[j] == 0) {
                printf("%d, ", j);

                visited[j] = 1;
                
                distance[j] = distance[node] + 1;

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
    Graph* graph = createGraph(7);

    // add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);

    addEdge(graph, 1, 3);

    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);

    addEdge(graph, 3, 4);

    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);

    bfs(graph, 2);

    return 0;
}


