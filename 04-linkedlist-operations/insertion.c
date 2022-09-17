#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* ptr)
{
    while (ptr!=NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

// INSERT AT BEGINNING
struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = head;
    return node;
}

// INSERT AT THE END
void insertAtLast(struct Node* ptr, int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    while(ptr!=NULL) {
       if(ptr->next==NULL) {
          node->data = data;
          node->next = NULL;
          ptr->next = node;
          break;
       }
       ptr = ptr->next;
    }
}

// INSERT AFTER
void insertAfter(struct Node* ptr, struct Node* prevNode, int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data ;
    
    struct Node* temp = prevNode->next;
    prevNode->next = node;
    node->next = temp;
}

// INSERT AT INDEX
void insertAtIndex(struct Node* ptr, int data, int index) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node*)) ;
    int i = 0 ;
    while(ptr!=NULL) {
       if(i==index - 1) {
          node->data = data;
          node->next = ptr->next;
          ptr->next = node;
          break;
       }
       ptr = ptr->next;
       i++;
    }
}



int main() {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* two = (struct Node*) malloc(sizeof(struct Node));
    struct Node* three = (struct Node*) malloc(sizeof(struct Node));
    struct Node* four = (struct Node*) malloc(sizeof(struct Node));
    struct Node* five = (struct Node*) malloc(sizeof(struct Node));

    head->data = 3 ;
    head->next = two ;

    two->data = 5;
    two->next = three;

    three->data = 9;
    three->next = four;

    four->data = 12;
    four->next = five;

    five->data = 15;
    five->next = NULL;

    // INSERT AT FIRST
    /*
    printf("BEFORE INSERT AT FIRST :\n");
    traverse(head) ;
    head = insertAtFirst(head, 44);
    printf("AFTER INSERT AT FIRST :\n");
    traverse(head);
    */


    // INSERT AT LAST
    /*
    printf("BEFORE INSERT AT LAST :\n");
    traverse(head);
    insertAtLast(head, 888);
    insertAtLast(head, 999);
    printf("AFTER INSERT AT LAST: \n");
    traverse(head); 
    */

    
    // INSERT AFTER
    /*
    printf("BEFORE INSERT AFTER :\n");
    traverse(head);
    insertAfter(head, two, 888);
    printf("AFTER INSERT AFTER: \n");
    traverse(head); 
    */

    
    // INSERT AT INDEX
    printf("BEFORE INSERT AT INDEX :\n");
    traverse(head);
    insertAtIndex(head, 88, 4);
    printf("AFTER INSERT AT INDEX: \n");
    traverse(head); 


    return 0;
}