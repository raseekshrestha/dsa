#include <iostream>
using namespace std;

int top = -1;


void push(int * arr,int size,int data){
    if (size - 1 == top ){ //check if the stack is full
        cout << "stack overflow" << endl;
        exit(0);
    }else{
        arr[++top] = data;
    }
}

void print(int * arr){
    cout << "stack = [ ";
    for (int i= 0;i<= top;i++){
        cout << arr[i] << " ";
    }
    cout << "]";
}

void pop(int *arr){
    // check if the stack is empty
    if (top < 0){
        cout << "Error, stack is already empty"<<endl;
    }
    else{
        top -= 1;
    }
}



int main(){
    int size;
    cout << "Enter size of stack: "; cin >> size;
    int arr[size];
    push(arr,size,1);
    push(arr,size,2);
    push(arr,size,3);
    push(arr,size,4);
    push(arr,size,5);
    push(arr,size,55);
    pop(arr);

    print(arr);
    cout << "\ntop to stack is at "<< top << endl;
}