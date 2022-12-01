#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*tail;

void traverse();

void createCLL(){
    int choice=1;
    struct node *newnode;
    tail=0;
    while (choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d", &newnode->data);

        if(tail==NULL){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Do u want to continue : ");
        scanf("%d", &choice);
    }
    traverse();
}

void traverse(){
    struct node *temp=tail->next;
    while(temp->next!=tail->next){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("%d", temp->data);
    printf("\n");
}

int main(){
    createCLL();
    return 0;
}