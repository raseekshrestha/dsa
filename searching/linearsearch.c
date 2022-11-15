#include <stdio.h>

int linearSearch(int arr[],int size,int searchFor){
    for (int i=0;i<size;i++){
        if (arr[i] == searchFor){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,3,5,7,9,6,8,3,2,6};
    int size = sizeof(arr) / sizeof(int);
    int searchFor = 2;
    int indexof = linearSearch(arr,size,searchFor);
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