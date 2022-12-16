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


// INSERT
// Insert Recursively
struct Node* insert(struct Node* root, int key) {
        if(root == NULL) {
            return createNode(key);
        }

        
        if(key == root->data) {
           printf("This node already exists\n");
           return root;
        }
        if(key < root->data) {
            root->left = insert(root->left, key);
        }
        if(key > root->data) {
            root->right = insert(root->right, key);
        }

        return root;

}




// DELETION
struct Node* deleteNode(struct Node *root, int value){

    if(root == NULL) {
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
        if(root->left == NULL && root->right == NULL) {
            struct Node* temp = root;
            root = NULL;
            free(temp);
        }
        else if(root->left != NULL && root->right == NULL) {
            root = root->left;
        }
        else if(root->left == NULL && root->right != NULL) {
            root = root->right;
        }
        else {
            struct Node* ipre = ipredecessor(root);
            printf("\nipre == %d \n", ipre->data);
            root->data = ipre->data;
            // modify root left tree (root->left) after deletion in root left tree.
            root->left = deleteNode(root->left, ipre->data);
        }
    }

    // return updated not 
    return root ;
}


int main()
{

   struct Node* root = insert(NULL, 50);

   insert(root, 40);
   insert(root, 60);
   insert(root, 20);
   insert(root, 45);
   insert(root, 55);
   insert(root, 70);
   insert(root, 40);
   insert(root, 43);
   insert(root, 42);
   insert(root, 44);




    // binary search tree
    /*
               50
              /   \
             40    60
           /  \    /  \
          20  45  55   70
              / 
            43  
           /  \
          42  44

    
    */


    inOrder(root);

    printf("\n%d \n", isBST(root));

    // DELETE NODE
    int key = 50;
    deleteNode(root, key);
    printf("\nAfter deleting %d: \n", key) ;
    inOrder(root);


    return 0;
}









