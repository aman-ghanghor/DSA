#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

// TRAVERSAL
void inOrder(struct Node *root)
{
    if(root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key); 
        inOrder(root->right);
    }
}

int getHeight(struct Node* n) {
    if(n == NULL) {
        return 0;
    }
    return n->height;
}

// CREATE NODE
struct Node* createNode(int key) {
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    
    return n;
}

// GET BALANCED FACTOR 
int getBalanceFactor(struct Node* n) {
    if( n == NULL) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

int max(int a, int b) {
    if(a > b) {
        return a;
    }
    if(b > a) {
        return b;
    }
}

struct Node* leftRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2= x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Height. In a tree data structure, the number of edges from the leaf node to the 
// particular node in the longest path is known as the height of that node

struct Node* rightRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2= y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return y;
}

struct Node* insert(struct Node* node, int key) {
    if(node == NULL) {
        return createNode(key);
    }

    if(key < node->key) {
        node->left = insert(node->left, key);
        return node;
    }
    else if(key > node->key) {
        node->right = insert(node->right, key);
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // find balanced factor
    int bf = getBalanceFactor(node);

    // LEFT LEFT CASE
    if(bf > 1 && key < node->left->key) {
        return rightRotate(node);
    }


    // RIGHT RIGHT
    if(bf < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // LEFT RIGHT
    if(bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RIGHT LEFT
    if(bf < -1 && key < node->right->key) {
        node->right = rightRotate(node->left);
        return leftRotate(node);
    }

    return node;

}


int main() {
    struct Node* root = NULL;

    root = insert(root, 45);
    root = insert(root, 50);
    root = insert(root, 55);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 88);

    inOrder(root);

    return 0;
}