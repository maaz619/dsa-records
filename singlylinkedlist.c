#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} * head, *newnode, *temp, *prevnode, *currnode, *nextnode;

void operation();
void print();

void createlist()
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
            temp->link = newnode;
            temp = temp->link;
        }
        printf("Do you want to continue : ");
        scanf("%d", &choice);
    }
    if (choice == 0)
    {
        operation();
    }
}

void insertatbeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &newnode->data);
    newnode->link = head;
    head = newnode;
    print();
    int another;
    printf("Do you want to add another data : ");
    scanf("%d", &another);
    if (another == 1)
    {
        insertatbeg();
    }
}

void insertatend()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &newnode->data);
    temp->link = newnode;
    temp = newnode;
    print();
    int another;
    printf("Do you want to add another data : ");
    scanf("%d", &another);
    if (another == 1)
    {
        insertatend();
    }
}

void insertatrandom()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);

    int pos;
    printf("Enter Position : ");
    scanf("%d", &pos);

    int i = 1;
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
    print();
    int another;
    printf("Do you want to add another data : ");
    scanf("%d", &another);
    if (another == 1)
    {
        insertatrandom();
    }
}

void reverse()
{
    prevnode = NULL;
    currnode = head;
    nextnode = head;
    while (nextnode->link != 0)
    {
        nextnode = currnode->link;
        currnode->link = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    currnode->link = prevnode;
    head = nextnode;
    while (nextnode != 0)
    {
        printf("%d ", nextnode->data);
        nextnode = nextnode->link;
    }
    printf("\n");
}

void deleteatbeg()
{
    temp = head;
    head = temp->link;
    free(temp);
    print();
}

void deleteatend()
{
    temp = head;
    prevnode = temp;
    while (temp->link != NULL)
    {
        prevnode = temp;
        temp = temp->link;
    }
    prevnode->link = NULL;
    free(temp);
    print();
}

void deleteatrandom()
{
    int i = 1, pos;
    printf("Enter the position : ");
    scanf("%d", &pos);
    temp = head;
    prevnode = temp;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    free(prevnode->link);

    print();
}

void print()
{
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void operation()
{
    print();
    int key;
    while (key != 0)
    {
        printf("Which operation do you want to continue : \n");
        printf("1. = Insert at beginning.\n2. = Insert at random.\n3. = Insert at endding.\n4. = Reverse the linkedlist.\n5. = Delete at begining\n6. = Delete at end\n7. = Delete at random\n0. = Just print & exit.\n");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            insertatbeg();
            break;
        case 2:
            insertatrandom();
            break;
        case 3:
            insertatend();
            break;
        case 4:
            reverse();
            break;
        case 5:
            deleteatbeg();
            break;
        case 6:
            deleteatend();
            break;
        case 7:
            deleteatrandom();
            break;
        case 0:
            print();
            break;
        default:
            printf("Invalid input!");
        }
    }
}

int main()
{
    printf("-------------------\n");
    printf("1. = YES 0. = NO\n");
    printf("-------------------\n");

    createlist();

    return 0;
}
