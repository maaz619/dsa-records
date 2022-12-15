#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
} * head, *tail;

void traverse();

void createDCLL()
{
    int choice = 1;
    head = 0;
    struct node *newnode;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = tail = newnode;
            tail->next = tail;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        printf("Do u want to continue : ");
        scanf("%d", &choice);
    }
    traverse();
}

void insertAtBeg()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head->prev = newnode;
    newnode->prev = tail;
    tail->next = newnode;
    head = newnode;

    int another;
    printf("Do u insert more data at beg : ");
    scanf("%d", &another);
    if (another)
    {
        insertAtBeg();
    }
}

void insertAtEnd()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    newnode->prev = tail;
    tail->next = newnode;
    head->prev = newnode;
    tail = newnode;

    int another;
    printf("Do u insert more data at end : ");
    scanf("%d", &another);
    if (another)
    {
        insertAtEnd();
    }
}

void insertAtPos()
{
    int pos, i = 1;
    printf("Enter Position : ");
    scanf("%d", &pos);

    struct node *temp, *newnode;
    temp = head;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);

    if (pos == 1)
    {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
    else
    {

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
    int another;
    printf("Do u insert more data at pos : ");
    scanf("%d", &another);
    if (another)
    {
        insertAtPos();
    }
}

void insertion()
{
    int choice = 1, key;
    while (choice)
    {
        printf("1. = insertAtBeg\n2. = insertAtEnd\n3. = insertAtPos\n");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            insertAtBeg();
            traverse();
            break;
        case 2:
            insertAtEnd();
            traverse();
        case 3:
            insertAtPos();
            traverse();
        default:
            break;
        }
        printf("Do u want to continue : ");
        scanf("%d", &choice);
    }
    traverse();
}

void traverse()
{
    struct node *temp;
    temp = head;
    while (temp->next != tail->next)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main()
{
    createDCLL();
    insertion();
    return 0;
}