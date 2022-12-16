#include <stdio.h>
#include <stdlib.h>

int v = 7;

// ====== Stack =======
struct Stack {
    int size;
    int top;
    int* arr;
} ;

// CREATE STACK
struct Stack* createStack(int size) {
    struct Stack* s = (struct Stack*) malloc(sizeof(struct Stack));
    s->size = size;
    s->top = -1;
    s->arr = (int*) malloc(size * sizeof(int));
    
    return s;
}

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


// ============= DEPTH FIRST SEARCH (DFS) Algorithm ==============

// As function call stored in stack in C. so we can use recursive.
int visited[7] = {0, 0, 0, 0, 0, 0, 0};

void dfs1(int graph[][v], int i) {
    printf("%d, ", i);
    visited[i] = 1;

    for(int j = 0; j < v; j++) {
        if(graph[i][j]==1 && visited[j]== 0) {
            dfs1(graph, j);
        }
    }
} 


// explicitely using our custom stack

void dfs2(int graph[][v], int startedVertex) {
    struct Stack* s = createStack(100);
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    int i = startedVertex;

    // visit first node
    push(s, i);

    while(!isEmpty(s)) {
        int node = pop(s);

        if(visited[node] == 0) {
            visited[node] = 1;
            printf("%d, ", node);
        }

        for(int j=0; j < v; j++) {
            if(graph[node][j]==1 && visited[j]==0) {
                push(s, j);
            }
        }

    }

}







int main() {
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

    dfs1(graph, 0);
    printf("\n");
    dfs2(graph, 0);

    return 0;
}