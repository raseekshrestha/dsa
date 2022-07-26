#include <iostream>
using namespace std;
#define SIZE 5

int rear = -1, front = -1;
int queue[SIZE];

bool isEmpty(){
    if ((rear == -1 && front == -1) || front > rear){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(){
    return (rear == SIZE - 1) ? true : false;
}

void enqueue(int a){
    if (isFull()){
        cout << "queue is full\n";
        exit(0);
    }
    (rear == -1 && front == -1) ? front++ : front;
    queue[++rear] = a;
    
}

void dequeue(){
    if (isEmpty()){
        cout << "queue is already Empty";
        return;
    }
    front++;
}

void printQueue(){
    cout << "[";
    for (int i=front;i<=rear;i++){
        cout << " " << queue[i];
    }
    cout << " ]";
}

int main(){
    cout << "Enqueue 1,2,3,4\n";
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printQueue();
    cout << "\n\nAfter Dequeue\n";
    dequeue();
    printQueue();

    cout << "\n\nEnqueue 55\n";
    enqueue(55);
    printQueue();

    cout << "\n\nEnqueue 56\n";
    enqueue(56);

    
}