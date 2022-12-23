#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *top = 0, *temp;

void push()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);
    newnode->link = top;
    top = newnode;
}

void pop()
{
    temp = top;
    printf("Pop element is %d\n", temp->data);
    top = temp->link;
    free(temp);
}

void peek()
{
    printf("Peek element is %d\n", top->data);
}

void display()
{
    printf("Displaying stack : \n");
    for (temp = top; temp != 0; temp = temp->link)
    {
        printf("%d\n", temp->data);
    }
}

void operation()
{
    int choice;
    printf("Enter Operation : \n");
    do
    {
        printf("1. = push\n2. = pop\n3. = peek\n4. = display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            break;
        }
        printf("Do u want to continue : ");
        scanf("%d", &choice);
    } while (choice != 0);
    printf("Final ");
    display();
}

int main()
{
    operation();
    return 0;
}