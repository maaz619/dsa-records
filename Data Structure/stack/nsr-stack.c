// To run this file you have to download "stack.h" file in the same folder or location.

#include<stdio.h>
#include<limits.h>
#include"stack.h"

int main(){
  int arr[4]={1,3,2,4},arr1[4];
  STACK *n= create(4);
  for(int i=4-1;i>=0;i--){
    if(arr[i]==arr[4-1]){
      arr1[i]=-1;
      push(arr[i],n);
    }
    else if(n->arr[n->top]<arr[i]){
      arr1[i]=n->arr[n->top];
      push(arr[i],n);
    }
    else while(n->arr[n->top]>arr[i]){
           printf("element popped %d\n",pop(n));
           if(n->top==-1){
             arr1[i]=-1;
             push(arr[i],n);
             break;
           }
    }
  }
  for(int i=4-1;i>=0;i--){
    printf("%d\n",arr1[i]);
  }
}
