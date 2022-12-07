#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*tail,*newnode;

void traverse();

void createCLL(){
    int choice=1;
    tail=0;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d", &newnode->data);
        if(tail==0){
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

void reverse(){
    struct node *prevnode, *currnode, *nextnode;
    currnode=tail->next;
    nextnode=currnode->next;
    while (currnode!=tail)
    {
        prevnode=currnode;
        currnode=nextnode;
        nextnode=currnode->next;
        currnode->next=prevnode;
    }
    nextnode->next=tail;
    tail=nextnode;
    traverse();
}

void traverse(){
    struct node *temp;
    temp=tail->next;
    while(temp->next!=tail->next){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("%d\n", temp->data);
}

int main(){
    createCLL();
    reverse();
    return 0;
}