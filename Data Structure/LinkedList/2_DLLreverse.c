#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
}*head,*tail;

void traverse();

void create(){
    int choice=1;
    head=NULL;
    while (choice)
    {
        struct node *newnode;
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d", &newnode->data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("Do u want to continue : ");
        scanf("%d", &choice);
    }
    traverse();
}

void traverse(){
    struct node *temp;
    temp=head;
    while (temp!=0)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverse(){
    struct node *currnode, *nextnode;
    if(head==NULL){
        printf("list is empty!");
    }
    else{
        currnode=head;
        while(currnode!=0){
            nextnode=currnode->next;
            currnode->next=currnode->prev;
            currnode->prev=nextnode;
            currnode=nextnode;
        }
        currnode=head;
        head=tail;
        tail=currnode;
    }
    traverse();
}

int main(){
    create();
    reverse();
    return 0;
}