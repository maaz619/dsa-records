#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head, *temp;

void traverse();

void create(){
    int choice=1;
    head==NULL;
    while(choice){
        struct node *newnode;
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d", &newnode->data);
        if(head==NULL){
            head=newnode;
        }
        else{
            temp->next=newnode;
        }
        temp=newnode;
        printf("Do u want to add more data : ");
        scanf("%d", &choice);
    }
    traverse();
}

void traverse(){
    temp=head;
    while (temp!=0)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverse(){
    struct node *prevnode, *currnode, *nextnode;
    prevnode=0;
    currnode=head;
    nextnode=head;
    while(nextnode!=0){
        nextnode=nextnode->next;
        currnode->next=prevnode;
        prevnode=currnode;
        currnode=nextnode;
    }
    head=prevnode;
    traverse();
}

int main(){
    create();
    reverse();
    return 0;
}