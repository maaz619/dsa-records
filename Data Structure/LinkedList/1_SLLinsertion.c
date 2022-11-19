#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * newnode, *head, *temp;

void traverse();

void create()
{
    int choice = 1;
    head = NULL;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d", &newnode->data);
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        printf("Do u want to continues : ");
        scanf("%d", &choice);
    }
    printf("\n");
    traverse();
    printf("\n");
}

void insertAtBeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;

    int another;
    printf("Do u want to add more at beginning : ");
    scanf("%d", &another);
    if (another)
    {
        insertAtBeg();
    }
    else
    {
        traverse();
        printf("\n");
    }
}

void insertAtIndex()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);

    int i = 0, pos;
    printf("Enter Index : ");
    scanf("%d", &pos);

    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    int another;
    printf("Do u want to add more at index : ");
    scanf("%d", &another);
    if (another)
    {
        insertAtIndex();
    }
    else
    {
        traverse();
        printf("\n");
    }
}

void insertAtEnd(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);

    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;

    int another;
    printf("Do u want to add more at ending : ");
    scanf("%d", &another);
    if (another)
    {
        insertAtEnd();
    }
    else
    {
        traverse();
        printf("\n");
    }
    
}

void insertAtPos(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);

    int i=1,pos;
    printf("Enter Position : ");
    scanf("%d", &pos);
    temp=head;
    while(i<pos-1){
        temp=temp->next;
        i++;
    } 
    newnode->next=temp->next;
    temp->next=newnode;

    int another;
    printf("Do u want to add more at between : ");
    scanf("%d", &another);
    if (another)
    {
        insertAtPos();
    }
    else
    {
        traverse();
        printf("\n");
    }
}

void traverse()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertion()
{
    int again=1;
    while (again)
    {
        printf("Enter Operation : \n");
        printf("1. = Insert at beginning.\n2. = Insert at index.\n3. = Insert at endding.\n4. = Insert Af Position.\n5. = Traverse.\n");
        int key;
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            insertAtBeg();
            break;
        case 2:
            insertAtIndex();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPos();
            break;
        case 5:
            traverse();
            break;
        default:
            break;
        }
        printf("Do u want to continue operation : ");
        scanf("%d", &again);
    }
    traverse();
}

int main()
{
    create();
    insertion();
    return 0;
}