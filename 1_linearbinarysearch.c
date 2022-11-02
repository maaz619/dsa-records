#include<stdio.h>

int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
    
}

int binarySearch(int arr[], int size, int element){
    int low,mid,high;
    low = 0;
    high = size-1;

    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        else if(arr[mid]<element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    // Unsorted array for linear search
    // int arr[] = {1,4,2,5,6,3,7,8,12,35,13,42,56};
    // int size = sizeof(arr)/sizeof(int);
    // int element = 12;

    // Sorted array for binary search
    int arr[] = {1,4,5,6,7,8,12,18,22,35,43,45,56};
    int size = sizeof(arr)/sizeof(int);
    int element = 43;

    int indexOfElement = linearSearch(arr,size,element);
    printf("Searching element is %d at index of %d\n",element, indexOfElement);

    return 0;
}