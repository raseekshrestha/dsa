#include <stdio.h>

int binarySearch(int arr[],int size,int searchFor){
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high){
        mid = (low + high) / 2;
        if (arr[mid] == searchFor){
            return mid;
        }
        if (arr[mid] > searchFor){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }

    }
}


int main(){
    int arr[] = {1,2,3,4,5,7,8,9};
    int size = sizeof(arr) / sizeof(int);
    int searchFor = 8;
    int indexof = binarySearch(arr,size,searchFor);
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    if (indexof >=0){
        printf("found at index %d",indexof);
    }else{
        printf("not found");
    }
}