#include <stdio.h>
#include <stdlib.h>

int getKey(int x,int size){
    return x % size;
}

void generateHashTable(int *hash,int *arr,int size){
    int key;
    for (int i=0;i<size;i++){
        hash[i] = -1;
    }
    for (int i=0;i<size;i++){
        key = getKey(arr[i],size);
        if (hash[key] == -1){
            hash[key] = arr[i];
        }
        else{ // collision occured
            //solving collision through linear probing
            while (hash[key] != -1){
                key = getKey(key+1,size);
            }
            hash[key] = arr[i];
        }
    }
}

int searchFromHashTable(int hash[],int searchFor,int size){
    int key = getKey(searchFor,size);
    if (hash[key] == searchFor){
        return key;
    }
    for (int i=0;i<size;i++){
        key = getKey(key+1,size);
        if (hash[key] == searchFor){
            return key;
        }
    }
    return -1;
}


int main(){
    int arr[] = {1,4,5,7,3,8,9};
    
    int size = sizeof(arr) / sizeof(int);
    int hash[size]; //key will be the index 
    
    generateHashTable(&hash[0],&arr[0],size);

    printf("hash table is : \n");
    printf("-----------------\n");
    printf("| Key \t| values|\n");
    printf("--------+--------\n");
    for (int i=0;i<size;i++){
        printf("| %d\t| %d\t|\n",i,hash[i]);
    }
    printf("-----------------\n");   

    int searchFor = 8;
    int result = searchFromHashTable(hash,searchFor,size);
    printf("%d found at index %d",searchFor,result);
}