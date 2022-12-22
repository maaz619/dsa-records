#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int size, top = -1;
int stack[SIZE];

void push()
{
    for (int i = 0; i < size; i++)
    {

        int x;
        printf("Enter Data : ");
        scanf("%d", &x);
        if (top == size - 1)
        {
            printf("Stack is Overflow, so data will not inserted into the stack.\n");
            break;
        }
        else
        {
            top++;
            stack[top] = x;
        }
    }
}

void pop()
{
    int ele;
    if (top == -1)
    {
        printf("Stack is Underflow\n");
    }
    else
    {
        ele = stack[top];
        printf("Poped element is %d\n", ele);
        top--;
    }
}

void peek()
{
    int ele;
    if (top == -1)
    {
        printf("Stack is Underflow\n");
    }
    else
    {
        ele = stack[top];
        printf("Peek element is %d\n", ele);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is Underflow");
    }
    else
    {
        printf("Displaying Stack : \n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    printf("Enter size : ");
    scanf("%d", &size);
    int choice;
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
    display();
    return 0;
}