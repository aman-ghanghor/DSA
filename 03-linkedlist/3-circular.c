#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void cllTraverse(struct Node *head)
{
    struct Node *p = head;
    do
    {
        printf("%d \n", p->data);
        p = p->next;
    } while (p != head);
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *two = (struct Node *)malloc(sizeof(struct Node));
    struct Node *three = (struct Node *)malloc(sizeof(struct Node));
    struct Node *four = (struct Node *)malloc(sizeof(struct Node));
    struct Node *five = (struct Node *)malloc(sizeof(struct Node));

    head->data = 32;
    head->next = two;

    two->data = 9;
    two->next = three;

    three->data = 4;
    three->next = four;

    four->data = 2;
    four->next = five;

    five->data = 5;
    five->next = head;

    cllTraverse(head);

    return 0;
}






