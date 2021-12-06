#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Pointer to the head node (or) name of the linked list

void Insert(int x, int n){
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1 ->data = x;
    if (n == 1){
        temp1 ->next = head;
        head = temp1;
        return;
    }
    int i; 
    struct Node* temp2 = head;
    for ( i = 0; i < n-2; i++)
    {
        temp2 = temp2 ->next;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1; 
}

void Delete(int n){
    struct Node* temp1 = head;
    if(n == 1){
        head = temp1 -> next;
        free(temp1);
        return;
    }
    int i;
    for (i = 0; i < n-2; i++){
        temp1  = temp1 ->next;
    }
    struct Node* temp2 = temp1  ->next;
    temp1->next = temp2->next;
    free(temp2);
}

//Print all the nodes from beginning to end.
void Print(){
    struct Node* temp = head;
    printf("The list is:");
    while(temp != NULL){
        printf("    %d", temp ->data);
        temp = temp ->next;
    }
    printf("\n");
}
 
void main(){

        Insert(5,1);
        Insert(6,2);
        Insert(7,3);
        Insert(1,2);
        Print();
    }