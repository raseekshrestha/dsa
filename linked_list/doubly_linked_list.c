#include <stdio.h>
#include <stdlib.h>

struct theNode{
    int data;
    struct theNode *prev;
    struct theNode *next;
};

typedef struct theNode Node; 
Node *head = NULL;
Node *tail = NULL;

Node *getNode(){
    Node *n1;
    n1 = (Node*)malloc(sizeof(Node));
    return n1;
}

void insertBeg(int x){
    Node *ptr = getNode();
    ptr->data = x;
    ptr->next = head;
    ptr->prev = NULL;
    head = ptr;
}

void insertEnd(int x){
    if (head == NULL){
        printf("Empty so adding to beginning\n");
        insertBeg(x);
    }
    else{
        Node *newNode = getNode();
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        
    }

}

void display(){
    if (head == NULL){
        printf("Empty list. Nothing to display\n");
    }
    Node *ptr = head;
    printf("forward Traverse:\n");
    while(ptr->next!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\ntraversing backward:\n");
    ptr = tail;
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->prev;
    }
}

void insert(int x,int index){
    if (head == NULL){
        printf("Empty List: index out of range");
        return;
    }
    if (index ==0){
        insertBeg(x);
        return;
    }
    Node *currentNode = head;
    for (int i=0;i<index;i++){
        currentNode = currentNode->next;
    }
    Node *newNode = getNode();
    newNode->data = x;
    newNode->next = currentNode;
    newNode->prev = currentNode->prev;
    currentNode->prev->next = newNode;
    currentNode->prev = newNode;

}

void deleteEnd(){
    if (head==NULL){
        printf("Cannot delete. List is already empty\n");
        return;
    }
    // NodeType *prev = getnode();
    Node *currentNode = head;

    while (currentNode->next!=NULL){
        currentNode = currentNode->next;
    }
    currentNode->prev->next = NULL;
    free(currentNode);
}



int main(){
    insertEnd(5);
    // insertEnd(4);
    // insertEnd(3);
    // insert(110,0);
    // deleteEnd();
    display();
}