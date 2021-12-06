#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int arr[MAX_SIZE];
int top = -1;

void Push(int x){
    if(top == MAX_SIZE - 1){
        printf("Stack Overflow\n");
        return;
    }
    arr[++top] = x;
}

void Pop(){
    if(top == -1){
        printf("No element to pop\n.");
        return;
    }
    top--;
}

int Peek(){
    return arr[top];
}

int IsEmpty(){
    if(top == -1)
        return 1;   
}

void main(){
    Push(21);
}