#include <stdio.h>
#include <stdlib.h>

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



int main() {
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);

    printGraph(graph);


    return 0;

}





