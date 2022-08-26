#include <stdio.h>
void bubbleSort(int *arr,int size){
    int temp;
    for (int i=0;i<size-1;i++){
        for (int j=0;j<size -1 -i;j++){
            if (arr[j] > arr[j+1]){
                temp  = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void printarr(int *arr,int size){
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int size = 5;
    int arr[size] = {1,5,4,7,2};
    printf("Before Sorting\n");
    printarr(&arr[0], size);
    bubbleSort(&arr[0],size);
    printf("\nAfter Sorting\n");
    printarr(&arr[0],size);
}