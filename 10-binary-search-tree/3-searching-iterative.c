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

    // SEARCHING
    int ele = 55;
    struct Node* searchedElement = searchIter(p, ele);
   
    if(searchedElement==NULL) {
        printf("%d NOT FOUND \n", ele);
    }
    else {
        printf("SEARCHED ELEMENT: %d \n", searchedElement->data);
    }



    return 0;
}
