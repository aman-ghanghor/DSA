// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>



/*
struct Node {
    int data;
    struct Node*;
}; 
*/

typedef struct ListNode {
    int data;
    struct ListNode* next;
} * Node;





// Is empty
int isEmpty(Node ptr) {
    if(ptr == NULL) {
        return 1;
    }
    return 0;
}

// Traversal
void traverse(Node ptr) {
    if(!isEmpty(ptr)) {
        while (ptr!=NULL)
        {
            printf("%d \n", ptr->data);
            ptr = ptr->next;
        }
    }
    else {
        printf("Linked List is empty !!");
    }
}

// Insert at end
void insertAtEnd(Node head, int data) {
    Node ptr = head;
    Node node = (Node) malloc(sizeof(Node));
    
    if(!isEmpty(head)) {
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
    else {
        printf("Linked List is empty !!");
    }
}

// Insert at start
Node insertAtStart(Node head, int data) {
    Node node = (Node) malloc(sizeof(Node));
    node->data = data;
    
    if(isEmpty(head)) {
        node->next = NULL;
        return node;
    }
    else {
        node->next = head;
        return node;
    }
}

// Insert at index
Node insertAtIndex(Node head, int data, int index) {
    Node p = head ;
    Node q = head->next;
    int i = 0;
    
    Node node = (Node) malloc(sizeof(Node));
    node->data = data;
    
    if(index == 0) {
        return insertAtStart(head, data);
    }
    
    if(!isEmpty(head)) {
        
        while(q != NULL) {
            if(i == index - 1) {
               node->next = q ;
               p->next = node;
               return head;
            }
            i++;
            p = p->next;
            q = q->next;
        }
    }
    else {
        printf("Linked List is empty !!");
    }
}



// Remove from end
Node removeFromEnd(Node head) {
    Node p = head;
    Node q = head->next;
    
    if(!isEmpty(head)) {
       while(q->next != NULL) {
           p = p->next;
           q = q->next;
       }
       p->next = NULL;
       free(q);
       return head;
    }
    else {
        printf("Linked List is empty !!");
    }
}

// Remove from start
Node removeFromStart(Node head) {
    if(!isEmpty(head)) {
        Node node = head->next;
        free(head);
        return node;
    }
    else {
        printf("Linked List is empty !!");
    }
}

// Remove from index
Node removeFromIndex(Node head, int index) {
    Node p = head ;
    Node q = head->next;
    int i = 0;
    
    if(!isEmpty(head)) {
        
        while(q != NULL) {
            if(i == index - 1) {
                p->next = q->next;
                return head;
            }
            i++;
            p = p->next;
            q = q->next;
        }
    }
    else {
        printf("Linked List is empty !!");
    }
}





int main() {
    Node head = (Node) malloc(sizeof(Node)) ;
    
    head->data = 4;
    head->next = NULL ;
  
    insertAtEnd(head, 5);
    insertAtEnd(head, 7);
    insertAtEnd(head, 8);
    insertAtEnd(head, 15);
    insertAtEnd(head, 14);
    
    printf("After Insert at end: \n");
    traverse(head);
    
    // :
    // :
    // :
    // : 
    
    printf("\nAfter Insert at starting: \n");
    head = insertAtStart(head, 1);
    traverse(head);
    
    // : 
    // :
    // :
    // :
    
    int index2 = 3;
    printf("\nInsert at index %d: \n", index2);
    head = insertAtIndex(head, 999, index2);
    traverse(head);
    
    // :
    // :
    // :
    // :
    
    printf("\nRemove from start: \n");
    head = removeFromStart(head);
    traverse(head);   
    
    // :
    // :
    // :
    // :

    printf("\nRemove from end: \n");
    head = removeFromEnd(head);
    traverse(head);
    
    // :
    // :
    // :
    // :
    
    int index1 = 3;
    printf("\nRemove from index %d: \n", index1);
    head = removeFromIndex(head, index1);
    traverse(head);
    

    return 0;
}