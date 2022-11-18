// To run this file you have to download "stack.h" file in the same folder or location.

#include<stdio.h>
#include<limits.h>
#include"stack.h"

int main(){
  int arr[7]={1,3,2,4,3,12,6},arr1[7];
  STACK *n= create(7);
  for(int i=0;i<7;i++){
    if(arr[i]==arr[0]){
      arr1[i]=-1;
      push(arr[i],n);
    }
    else if(n->arr[n->top]<arr[i]){
      arr1[i]=n->arr[n->top];
      push(arr[i],n);
    }
    else while(n->arr[n->top]>arr[i]){
           printf("%d popped from stack \n", pop(n));
           if(n->top==-1){
             arr1[i]=-1;
             push(arr[i],n);
             break;
           }
           else if(arr[i]>=n->arr[n->top]){
                    arr1[i]=n->arr[n->top];
                    push(arr[i],n);
                    break;
                }
    }
  }
  for(int i=0;i<7;i++){
    printf("%d\n",arr1[i]);
  }
}
