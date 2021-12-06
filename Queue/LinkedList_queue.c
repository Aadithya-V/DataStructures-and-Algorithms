#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> // Yet to include bool in the code below.

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int IsEmpty(){
    if (front == NULL && rear == NULL) return 1;
    else return 0;
}

void EnQueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp ->data = x;
    temp ->next =NULL;

    if (IsEmpty()) {
        front = rear = temp;
        return;
    }
    rear ->next = temp;
    rear = temp;
}

void DeQueue(){
    if(IsEmpty) return;
    struct Node* temp = front;
    if(front == rear) front = rear =NULL; 
    else front = front ->next;
    free(temp);
}

void main(){

}