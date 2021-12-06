#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* top = NULL;

 void push(int x){
     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
     temp ->data = x;
     temp ->link = top;
     top = temp;
}

void pop(){
    if (top == NULL) {
        printf("No element to pop.\n");
        return;
    }
    struct Node* temp;
    temp = top;
    top = top ->link;
    free(temp);
}


void main(){
    /* Code to create the stack.*/
}