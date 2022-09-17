#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};


// Left to right traverse
void ltr_traverse(struct Node* ptr)
{
    while (ptr!=NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

// Right to left traverse
void rtl_traverse(struct Node* ptr)
{
    while (ptr!=NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->prev;
    }
}



int main()
{
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* two = (struct Node*) malloc(sizeof(struct Node));
    struct Node* three = (struct Node*) malloc(sizeof(struct Node));
    struct Node* four = (struct Node*) malloc(sizeof(struct Node));
    struct Node* five = (struct Node*) malloc(sizeof(struct Node));

    head->data = 32;
    head->prev = NULL;
    head->next = two;

    two->data = 9;
    two->prev = head;
    two->next = three;

    three->data = 4;
    three->prev = two;
    three->next = four;

    four->data = 2;
    four->prev = three;
    four->next = five;

    five->data = 5; 
    five->prev = four; 
    five->next = NULL;

    printf("LEFT TO RIGHT TRAVERSE - \n") ;
    ltr_traverse(head);

    printf("\nRIGHT TO LEFT TRAVERSE - \n") ;
    rtl_traverse(five);

    return 0;
}





