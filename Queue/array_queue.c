#include<stdio.h>
#include<stdlib.h>
#define  MAX_SIZE 10
// Logical Circular Array:-
#define increment_rear ((rear+1) % MAX_SIZE)
#define increment_front ((front+1) % MAX_SIZE)

int Queue[MAX_SIZE];
int front = -1;
int rear = -1;


int IsFull(){
    if (increment_rear == front) return 1;
    else return 0;
}

int IsEmpty(){
    if(front == -1 && rear == -1) return 1; 
    else return 0; 
}

void EnQueue(int x){
    if(IsEmpty()) {
        //Initialising by pointing front and rear to starting index of array Queue.
        front = 0; 
        rear = 0;
    }
    else if (IsFull()) {
        printf("Queue is full.");
        return;
    }
    else rear = increment_rear; //Incrementing only if Queue has already been initialised.
    Queue[rear] = x; //Assigment for the 1st initialisation (rear = 0) and all other times when !IsFull and rear has been incremented.
}

void DeQueue(){
    if (IsEmpty()) return;
    else if (front == rear) {/* When there is all but one element left to be removed. The element sits on index front == rear. */ 
        /* Resetting the Queue to its initial empty state as incrementing front will take it one index ahead of rear.*/   
        front = -1;
        rear = -1;
    }    
    else front = increment_front;
    
}

void Peek(){
    if(!IsEmpty()) printf("%d\t",Queue[front]);
    else printf("Queue is empty.\n");
}

void main(){
    EnQueue(10);
    EnQueue(5);
    DeQueue();
    Peek();
    DeQueue();
    Peek();
    }