#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}


// TRAVERSAL
void inOrder(struct Node *root)
{
    if(root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data); 
        inOrder(root->right);
    }
}

// IS BINARY SEARCH TREE
int isBST(struct Node* root) {
    static struct Node* prev = NULL;
    if(root!=NULL) {
        if(!isBST(root->left)) {
            return 0;
        }

        if(prev != NULL && root->data <= prev->data) {
            return 0;
        }

        prev = root;
        return isBST(root->right);
    }
    else {
        return 1;
    }
}


struct Node* searchIter(struct Node* root, int value) {
    struct Node* ptr = root ;
    if(ptr != NULL) {
        while(ptr != NULL) {
            if(value == ptr->data) {
                return ptr ;
            }
            if(value < ptr->data) {
                ptr = ptr->left ;
            }
            if(value > ptr->data) {
                ptr = ptr->right;
            }
        }
        return NULL;
    }
}

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



// DELETION
struct Node* deleteNode(struct Node *root, int value){

    if(root == NULL) {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
 
    // searching the node
    if(value < root->data) {
       // this indicate the update in root left tree after deletion in root left tree
       // that is :
       root->left = deleteNode(root->left, value);   
    }
    else if(value > root->data) {
       // this indicate the update in root right tree after deletion in root right tree
       // that is : 
       root->right = deleteNode(root->right, value);
    }
    else {
        struct Node* ipre = ipredecessor(root);
        root->data = ipre->data;
        // modify root left tree (root->left) after deletion in root left tree.
        root->left = deleteNode(root->left, ipre->data);
    }
    // return the actual root address
    return root ;
}


int main()
{
    struct Node *p = createNode(50);
    struct Node *p1 = createNode(40);
    struct Node *p2 = createNode(60);

    struct Node *p11 = createNode(20);
    struct Node *p12 = createNode(45);

    struct Node *p21 = createNode(55);
    struct Node *p22 = createNode(70);



    // binary search tree
    /*
               50
              /   \
             40    60
           /  \    /  \
          20  45  55   70
          
    */

    // linking p to p1 and p2
    p->left = p1;
    p->right = p2;

    p1->left = p11;
    p1->right = p12;

    p2->left = p21;
    p2->right = p22;

    inOrder(p);

    printf("\n%d \n", isBST(p));

    // DELETE NODE
    printf("Deleted Node Value: %d \n", deleteNode(p, 50)->data) ;
    inOrder(p);

    return 0;
}









