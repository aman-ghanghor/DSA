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

// GET Inorder-predecessor
// IN ORDER PREDECCESSOR
struct Node* ipredecessor(struct Node* root) {
    // in-order predecessor is right most child of left subtree.
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

int max(int a, int b) {
    if(a > b) {
        return a;
    }
    if(b > a) {
        return b;
    }
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    x->right = T2;
    y->left = x;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Height. In a tree data structure, the number of edges from the leaf node to the 
// particular node in the longest path is known as the height of that node

struct Node* rightRotate(struct Node* x) {
    struct Node* y = x->left;
    struct Node* T2 = y->right;

    x->left = T2;
    y->right = x;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct Node* insert(struct Node* node, int key) {
    if(node == NULL) {
        return createNode(key);
    }

    if(key < node->key) {
        node->left = insert(node->left, key);
    }
    else if(key > node->key) {
        node->right = insert(node->right, key);
    }
    else {
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // find balanced factor
    int bf = getBalanceFactor(node);

    // Left Left
    if(bf > 1 && key < node->left->key) {
        node = rightRotate(node);
    }
    // Left Right
    if(bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        node = rightRotate(node);
    }

    // Right Right
    if(bf < -1 && key > node->right->key) {
        node = leftRotate(node);
    } 
    // Right Left
    if(bf < -1 && key < node->right->key) {
        node->right = rightRotate(node->right); 
        node = leftRotate(node);
    }


    return node;
}

// Deletion
struct Node* delete(struct Node* root, int key) {

    // STEP - 1 : stundard BST deletion

    if(root==NULL) {
       return NULL;
    }

    if(key < root->key) {
        root->left = delete(root->left, key);
    }
    else if(key > root->key) {
        root->right = delete(root->right, key);
    }
    else {

        if(root->left == NULL && root->right == NULL) {
            struct Node* temp = root;
            root = NULL;
            free(temp);
        }

        else if(root->left == NULL && root->right !=NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        }

        else if(root->left != NULL && root->right ==NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        }

        else {
            // left and right are not null
            struct Node* ipre = ipredecessor(root);
            root->key = ipre->key;

            root->left = delete(root->left, ipre->key);
        }

    }


    // If the tree had only one root
    // then return
    if (root == NULL) {
        return root;
    }


    // STEP - 2 : update the height of current root
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;


    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS root (to check whether this
    // root became unbalanced)
    int bf = getBalanceFactor(root);


    // Left Left case
    if(bf > 1 && getBalanceFactor(root->left) >= 0) {
       root = rightRotate(root);
    }

    // Left Right case
    if(bf > 1 && getBalanceFactor(root->left) < 0) {
       root->left = leftRotate(root->left);
       root = rightRotate(root);
    }

    // Right Right
    if(bf < -1  && getBalanceFactor(root->right) <= 0) {
       root = leftRotate(root);
    }

    // Right Left
    if(bf < -1 && getBalanceFactor(root->right) > 0) {
       root->right = rightRotate(root->right);
       root = leftRotate(root);
    }

    return root;

}





int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 80);
    root = insert(root, 60);
    root = insert(root, 85);
    root = insert(root, 82);
    root = insert(root, 20);
    root = insert(root, 35);
    root = insert(root, 32);
    root = insert(root, 40);

    inOrder(root);

    printf("\n");

    // delete 
    root = delete(root, 80);
    inOrder(root);
    

    return 0;
}