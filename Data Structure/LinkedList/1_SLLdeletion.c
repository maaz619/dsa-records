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
        printf("Do u want to add more data : ");
        scanf("%d", &choice);
    }
    traverse();
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

void insertAtEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);

    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;

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

void insertAtPos()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);

    int i = 1, pos;
    printf("Enter Position : ");
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

void deleteAtBeg()
{
    temp = head;
    head = head->next;
    free(temp);
    traverse();
}

void deleteAtIndex()
{
    int i = 0, index;
    printf("Enter Index : ");
    scanf("%d", &index);

    temp = head;
    struct node *prevnode = (struct node *)malloc(sizeof(struct node));
    while (i < index - 1)
    {
        temp = temp->next;
        i++;
    }
    prevnode = temp->next;
    temp->next = prevnode->next;
    free(prevnode);
    traverse();
}

void deleteAtEnd()
{
    struct node *prevnode;
    temp = head;
    while(temp->next!=0){
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head){
        head=0;
    }
    else{
        prevnode->next=0;
    }
    free(temp);
    traverse();
}

void deleteAtValue()
{
    int value;
    printf("Enter value : ");
    scanf("%d", &value);
    struct node *prevnode = (struct node *)malloc(sizeof(struct node));
    prevnode = head;
    temp = head->next;
    while (temp->data != value && temp->next != NULL)
    {
        prevnode = prevnode->next;
        temp = temp->next;
    }
    if (temp->data == value)
    {
        prevnode->next = temp->next;
        free(temp);
    }
}

void insertion()
{
    int again = 1;
    while (again)
    {
        printf("Enter Operation : \n");
        printf("1. = Insert at beginning.\n2. = Insert at index.\n3. = Insert at endding.\n4. = Insert Af Position.\n5. = Traverse.\n6. = Delete at beginning.\n7. = Delete at Index.\n8. = Delete at ending.\n9. = Delete at value.\n");
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
        case 6:
            deleteAtBeg();
            break;
        case 7:
            deleteAtIndex();
            break;
        case 8:
            deleteAtEnd();
            break;
        case 9:
            deleteAtValue();
            break;
        default:
            break;
        }
        printf("Do u want to continue operation : ");
        scanf("%d", &again);
    }
    traverse();
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

int main()
{
    create();
    insertion();
}