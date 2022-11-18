#include<stdlib.h>
#include<stdio.h>
struct stack{
  int top;
  int size;
  int *arr;
};
typedef struct stack STACK;

STACK* create(int max_elements){
  STACK *S;
  S= (STACK*)malloc(sizeof(struct stack ));
  S->arr=(int*)malloc(sizeof(int)*max_elements);
  S->top=-1;
  S->size=max_elements;
  return S;
};
int isFull(STACK *S){
  return S->top==S->size-1;
}
int isEmpty(STACK *S){
  return S->top==-1;
}
void push(int x,STACK *S){
  if(isFull(S)){
    printf("stack is full");
    return ;
  }
  S->arr[++S->top]=x;
  printf("%d pushed to stack\n", x);
}
int pop(STACK *S){
  if(isEmpty(S)){
    printf("stack emptied!!");
    return S->top;
  }
  if( S != NULL ) { 
    free( S->arr ); 
    free( S ); 
  } 
  return S->arr[S->top--];
}
void display(int size,STACK *S){
  if(isEmpty(S)) printf("stack underflow");
  else for(int i=0;i<size;i++){
    printf("%d\t",S->arr[S->top-i]);
  }
}
