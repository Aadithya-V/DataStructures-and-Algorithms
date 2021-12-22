#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max(a,b) (a >= b ? a : b)

//BST and Properties:
struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* GetNewNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode -> data = data;
    newNode -> left =  NULL;
    newNode -> right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root, int data){
    if (root == NULL){
        root = GetNewNode(data);
    }
    else if(data <= root->data){
        root-> left = Insert(root-> left, data);
    }
    else {
        root ->right = Insert(root ->right, data);
    }
return root;
}

bool Search(struct BstNode* root, int data){
    if (root == NULL) return 0;
    else if (root ->data == data) return 1;
    else if (data <= root ->data) return Search(root ->left, data);
    else return Search(root ->right, data);
}

struct BstNode* FindMin(struct BstNode* root){ //returns the min node or NULL if BST is empty. Deference it to get min data.
    if (root == NULL) return NULL;
    else if (root ->left == NULL) return root;
    else return FindMin(root ->left);
}

struct BstNode* FindMax(struct BstNode* root){ //returns the max node or NULL if BST is empty. Deference it to get max data.
    if (root == NULL) return NULL;
    else if (root-> right == NULL) return root;
    else return FindMax(root ->right);
}

int BstHeight(struct BstNode* root){  
   if (root  == NULL) return -1;
   return max(BstHeight(root ->left), BstHeight(root ->right)) + 1; 
}

bool IsBST(struct BstNode* root){ //returns true if BST, else false.

}

//Queue:
struct QNode{
    struct BstNode* ptr;
    struct QNode* next;
};

struct QNode* qFront = NULL;
struct QNode* qRear = NULL;

int QIsEmpty(){
    if (qFront == NULL && qRear == NULL) return 1;
    else return 0;
}

void EnQueue(struct BstNode* ptr){
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp ->ptr = ptr;
    temp ->next = NULL;

    if (QIsEmpty()) {
        qFront = qRear = temp;
        return;
    }

    qRear ->next = temp;
    qRear = temp;
    
}

struct BstNode* QFront(){
    return qFront ->ptr;
}

void DeQueue(){
    if (QIsEmpty()) return;

    struct QNode* temp = qFront;

    if (qFront == qRear) qFront = qRear = NULL;
    else qFront = temp ->next;

    free(temp);
}


//BST Traversals:
void LevelOrder(struct BstNode* root){
    if (root == NULL) return;

    EnQueue(root);
    
    while (!QIsEmpty()){
        struct BstNode* current = QFront();
        printf("%d\n", current ->data);
        if (current ->left != NULL) EnQueue(current ->left);
        if (current ->right != NULL) EnQueue(current ->right);
        DeQueue();
    }
}

void PreOrder(struct BstNode* root){
    if (root == NULL) return;
    printf("%d\n", root ->data);
    PreOrder(root ->left);
    PreOrder(root ->right);
}

void InOrder(struct BstNode* root){
    if (root == NULL) return;
    InOrder(root ->left);
    printf("%d\n", root ->data);
    InOrder(root ->right);
}

void PostOrder(struct BstNode* root){
    if (root == NULL) return;
    PostOrder(root ->left);
    PostOrder(root ->right);
    printf("%d\n", root ->data);
}


int main( void ){
    struct BstNode* root = NULL;  //Empty Tree. Root is the pointer to the root node. Not the root node itself.
    root = Insert(root,10);
    root = Insert(root,15);
    root = Insert(root,5);
    root = Insert(root,3);
    root = Insert(root,25);

    /* struct BstNode* Min = FindMin(root);
    struct BstNode* Max = FindMax(root); */

    int hd = BstHeight(root);
    printf("%d\n", hd);

    InOrder(root);

}