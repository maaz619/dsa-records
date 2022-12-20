#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
}*head,*tail;

void traverse();
void createDCLL(){
    int choice=1;
    head=0;
    while (choice)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d", &newnode->data);
        if(head==0){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        tail->next=head;
        printf("Do u want to continue : ");
        scanf("%d", &choice);
    }
    traverse();
    
}

void deleteAtBeg(){
    struct node *temp;
    temp=head;
    head=temp->next;
    head->prev=tail;
    tail->next=head;
    free(temp);
}

void deleteAtEnd(){
    struct node *temp;
    temp = tail;
    tail=temp->prev;
    tail->next=head;
    head->prev=tail;
    free(temp);
}

void deleteAtPos(){
    int i=1, pos;
    printf("Enter Pos : ");
    scanf("%d", &pos);

    struct node *temp;
    temp=head;
    while (i<pos)
    {
        temp=temp->next;
        i++;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    free(temp);
}

void deletion(){
    int choice=1, key;
    while (choice)
    {
        printf("1. = deleteAtBeg\n2. = deleteAtEnd\n3. = deleteAtPos\n");
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

void traverse(){
    struct node *temp;
    temp=head;
    while(temp!=tail){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("%d\n", temp->data);
}

int main(){
    createDCLL();
    deletion();
    return 0;
}