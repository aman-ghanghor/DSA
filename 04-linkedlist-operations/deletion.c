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

// DELETE FIRST
struct Node* deleteFromStart(struct Node* ptr) {
    struct Node* newHead = ptr->next;
    free(ptr);
    return newHead;
}

// DELETE LAST
void deleteFromEnd(struct Node* ptr) {
    struct Node* p = ptr ;
    struct Node* q = ptr->next;
    while (q->next!=NULL)
    {
        p = p->next ;
        q = q->next ;
    }
    p->next = NULL;
    free(q);
}

// DELETE FROM INDEX
void deleteFromIndex(struct Node* ptr, int index) {
    int i = 0;
    while(ptr!=NULL) {
        if(i == index -1) {
           struct Node* node = ptr->next ;
           ptr->next = ptr->next->next;
           free(node) ;
           break;
        }
        ptr = ptr->next;
        i++;
    }
}

/* ========= OR =======
void deleteFromIndex(struct Node* head, int index) {
    int i = 0;
    struct Node* p = head;
    struct Node* q = head->next;
    
    if(isEmpty(head)) {
        printf("Linked List is empty !!");
    }
    else {
        while(q != NULL) {
            if(i == index -1) {
                p->next = q->next;
                free(q);
                break;
            }
            
            i++;
            p = p->next;
            q = q->next;
        }
    }
}
*/




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


    // DELETE AT FIST
    /*
    printf("BEFORE DELETE FIRST \n");
    traverse(head);
    head = deleteFromStart(head);
    printf("AFTER DELETE FIRST \n");
    traverse(head);
    */
    

    // DELETE AT LAST
    /*
    printf("BEFORE DELETE LAST \n");
    traverse(head);
    deleteFromEnd(head);
    printf("AFTER DELETE LAST \n");
    traverse(head);
    */


    // DELETE AT INDEX
    printf("BEFORE DELETE FROM INDEX \n");
    traverse(head);
    deleteFromIndex(head, 3);
    printf("AFTER DELETE FROM INDEX \n");
    traverse(head);
    



    // DELETE BY VALUE


    return 0;
}