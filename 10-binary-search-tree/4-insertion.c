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


// Insert Iteratively
int insertIter(struct Node* root, int key) {

    if(root != NULL) {
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = key;
        n->left = NULL;
        n->right = NULL;

        struct Node* ptr = root ;

        while(ptr != NULL) {
            if(key < ptr->data) {
                if(ptr->left == NULL) {
                    ptr->left = n;
                    return 1;
                }
                else {
                    ptr = ptr->left;
                }
            }
            if(key > ptr->data) {
                if(ptr->right == NULL) {
                    ptr->right = n;
                    return 1;
                }
                else {
                    ptr = ptr->right;
                }
            }
        }

        return 0;

    }
}


// Insert Recursively
struct Node* insertRecur(struct Node* root, int key) {
        if(root == NULL) {
            return createNode(key);
        }
        
        if(key == root->data) {
           printf("This node already exists\n");
           return root;
        }
        if(key < root->data) {
            root->left = insertRecur(root->left, key);
        }
        if(key > root->data) {
            root->right = insertRecur(root->right, key);
        }

        return root;

}





int main()
{
    struct Node *root = createNode(50);
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
    root->left = p1;
    root->right = p2;

    p1->left = p11;
    p1->right = p12;

    p2->left = p21;
    p2->right = p22;

    inOrder(root);

    printf("\n%d \n", isBST(root));

    // INSERT

    // Insert Iteratively

    // if(insertIter(root, 46)) {
    //     printf("INSERTED SUCCESSFULLY \n");
    // }
    // else {
    //     printf("UNABLE TO INSERT \n");
    // }

    // Insert Recursively


    insertRecur(root, 62);

    inOrder(root);

    return 0;
}
