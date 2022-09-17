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

// recursive function to print nodes of tree
void recur(struct Node *n)
{
    printf("%d \n", n->data);
    if (n->left != NULL)
    {   
        recur(n->left);
    }
    if (n->right != NULL)
    {
        recur(n->right);
    }
}

// TRAVERSAL
void traversal(struct Node *root)
{
    struct Node *r = root;
    recur(r);
}

int main()
{
    struct Node *p = createNode(3);
    struct Node *p1 = createNode(5);
    struct Node *p2 = createNode(6);

    struct Node *p11 = createNode(23);
    struct Node *p12 = createNode(25);

    struct Node *p21 = createNode(30);
    struct Node *p22 = createNode(31);


    // linking p to p1 and p2
    p->left = p1;
    p->right = p2;

    p1->left = p11;
    p1->right = p12;

    p2->left = p21;
    p2->right = p22;

    traversal(p);

    return 0;
}
