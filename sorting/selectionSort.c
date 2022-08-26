#include<stdio.h>

void printarr(int *arr,int size){
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int size=10,min=0,temp;
    int arr[size] = {23,10,20,3,45,76,67,24,2,11};
    printf("Bofore sorting:\n");
    printarr(&arr[0],size);
    for (int i=0;i<size-1;i++){
        min = i;
        for (int j=i+1;j<size;j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (min!=i){
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }

    printf("\nAfter sorting:\n");
    printarr(&arr[0],size);
}