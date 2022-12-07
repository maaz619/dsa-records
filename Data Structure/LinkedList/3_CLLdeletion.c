#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * tail;

void traverse();

void createCLL()
{
    int choice = 1;
    tail = 0;
    while (choice)
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d", &newnode->data);
        if (tail == 0)
        {
            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        printf("Do u want to continues : ");
        scanf("%d", &choice);
    }
    traverse();
}

void deleteAtBeg()
{
    struct node *temp;
    temp = tail->next;
    tail->next = temp->next;
    free(temp);

    int another;
    printf("Do u delete more data from beg : ");
    scanf("%d", &another);
    if (another)
    {
        deleteAtBeg();
    }
}

void deleteAtEnd()
{
    struct node *currnode, *prevnode;
    currnode = tail->next;
    while (currnode->next != tail->next)
    {
        prevnode = currnode;
        currnode = currnode->next;
    }
    prevnode->next = tail->next;
    tail = prevnode;
    free(currnode);

    int another;
    printf("Do u delete more data from end : ");
    scanf("%d", &another);
    if (another)
    {
        deleteAtEnd();
    }
}

void deleteAtPos()
{
    struct node *temp, *nextnode;
    temp = tail->next;

    int i = 1, pos;
    printf("Enter Pos : ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid Position!");
    }
    else if (pos == 1)
    {
        deleteAtBeg();
    }
    else
    {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);

    int another;
    printf("Do u delete more data from pos : ");
    scanf("%d", &another);
    if (another)
    {
        deleteAtPos();
    }
}

void deletion()
{
    int choice = 1, key;
    while (choice)
    {
        printf("1. = DeleteAtBeg\n2. = DeleteAtEnd\n3. = DeleteAtPos\n");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            deleteAtBeg();
            traverse();
            break;
        case 2:
            deleteAtEnd();
            traverse();
            break;
        case 3:
            deleteAtPos();
            traverse();
            break;
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
    temp = tail->next;
    while (temp->next != tail->next)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main()
{
    createCLL();
    deletion();
    return 0;
}