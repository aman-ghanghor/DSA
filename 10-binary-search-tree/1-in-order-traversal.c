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






int main()
{
    struct Node *p = createNode(7);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(10);

    struct Node *p11 = createNode(2);
    struct Node *p12 = createNode(5);



    // binary search tree
    /*
                7
              /   \
             3     10
           /  \
          2    5
          
    */

    // linking p to p1 and p2
    p->left = p1;
    p->right = p2;

    p1->left = p11;
    p1->right = p12;

    inOrder(p);

    printf("\n%d", isBST(p));

    return 0;
}
