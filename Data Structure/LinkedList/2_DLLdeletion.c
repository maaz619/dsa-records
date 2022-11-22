#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
} * head, *tail;

void traverse();

void create()
{
    int choice = 1;
    head = NULL;
    while (choice)
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        newnode->prev = 0;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
        }
        tail = newnode;
        printf("Do u want to continue : ");
        scanf("%d", &choice);
    }
    traverse();
}

void deleteFromBeg()
{
    struct node *temp;
    temp = head;
    head->next->prev = 0;
    head = head->next;
    free(temp);

    int another;
    printf("Do u delete more data from Beg : ");
    scanf("%d", &another);
    if (another)
    {
        deleteFromBeg();
    }
}

void deleteFromEnd()
{
    struct node *temp;
    temp = tail;
    tail->prev->next = 0;
    tail = tail->prev;
    free(temp);

    int another;
    printf("Do u delete more data from End : ");
    scanf("%d", &another);
    if (another)
    {
        deleteFromEnd();
    }
}

void deleteFromPos()
{
    int pos, i = 1;
    printf("Enter Pos : ");
    scanf("%d", &pos);
    struct node *temp;
    temp = head;
    if (pos == 1)
    {
        temp=head;
        head->next->prev=0;
        head=head->next;
        free(temp);
        traverse();
    }
    else
    {
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        free(temp);
    }

    int another;
    printf("Do u delete more data from Random : ");
    scanf("%d", &another);
    if (another)
    {
        deleteFromPos();
    }
}

void deletion()
{
    int choice = 1;
    while (choice)
    {
        int key;
        printf("Enter Operation : \n");
        printf("1. = DeleteFromBeg\n2. = DeleteFromEnd\n3. = DeleteFromPos\n");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            deleteFromBeg();
            traverse();
            break;
        case 2:
            deleteFromEnd();
            traverse();
            break;
        case 3:
            deleteFromPos();
            traverse();
            break;
        default:
            break;
        }
        printf("Do u continue operation : ");
        scanf("%d", &choice);
    }
    traverse();
}

void traverse()
{
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    create();
    deletion();
    return 0;
}