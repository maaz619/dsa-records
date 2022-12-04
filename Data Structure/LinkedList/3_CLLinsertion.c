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

void insertAtBeg(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);
    newnode->next=tail->next;
    tail->next=newnode;

    int another;
    printf("Do add more data at beg : ");
    scanf("%d", &another);
    if(another){
        insertAtBeg();
    }
    traverse();    
}

void insertAtEnd(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
    
    int another;
    printf("Do add more data at beg : ");
    scanf("%d", &another);
    if(another){
        insertAtEnd();
    }
    traverse(); 
}

void insertAtPos(){
    struct node *newnode, *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newnode->data);
    int pos, i=1;
    printf("Enter Pos : ");
    scanf("%d", &pos);

    temp=tail->next;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;

    int another;
    printf("Do add more data at beg : ");
    scanf("%d", &another);
    if(another){
        insertAtPos();
    }
    traverse(); 
}

void insertion(){
    int key=1,choice;
    while(key){
        printf("1. = InsertAtBeg\n2. = InsertAtEnd\n3. = InsertAtPos\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtBeg();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPos();
            break;
        default:
            break;
        }
        printf("Do u continue more operation : ");
        scanf("%d", &key);
    }
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
    insertion();
    return 0;
}