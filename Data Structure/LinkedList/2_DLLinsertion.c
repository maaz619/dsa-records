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

void insertAtBeg(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);
    newnode->prev=0;
    newnode->next=0;

    head->prev=newnode;
    newnode->next=head;
    head=newnode;

    int another;
    printf("Do u add more data at beg : ");
    scanf("%d", &another);
    if(another==1){
        insertAtBeg();
    }
}

void insertAtEnd(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);
    newnode->prev=0;
    newnode->next=0;

    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;

    int another;
    printf("Do u add more data at beg : ");
    scanf("%d", &another);
    if(another==1){
        insertAtEnd();
    }
}

void insertAtPos(){
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);
    newnode->prev=0;
    newnode->next=0;

    int pos, i=1;
    printf("Enter Pos : ");
    scanf("%d", &pos);
    temp=head;
    while (i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;

    int another;
    printf("Do u add more data at beg : ");
    scanf("%d", &another);
    if(another==1){
        insertAtPos();
    }
}

void insertAfterPos(){
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);
    newnode->prev=0;
    newnode->next=0;

    int pos, i=1;
    printf("Enter Pos : ");
    scanf("%d", &pos);
    temp=head;
    while (i<pos)
    {
        temp=temp->next;
        i++;
    }
    
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;

    int another;
    printf("Do u add more data at beg : ");
    scanf("%d", &another);
    if(another==1){
        insertAfterPos();
    }
}

void insertion()
{
    int choice = 1;
    while (choice)
    {
        int key;
        printf("Enter Operation : \n");
        printf("1. = InsertAtBeg\n2. = InsertAtEnd\n3. = InsertAtPos\n4. = InsertAfterPos\n");
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
            break;
        case 3:
            insertAtPos();
            traverse();
            break;
        case 4:
            insertAfterPos();
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
    insertion();
    return 0;
}