#include<stdio.h>
#include<stdlib.h>

int stack[50];
int top = -1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int EvaluatePostfix(char* exp){
    register int i;
    for (i = 0; i < strlen(exp); i++){
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
                int op2 = pop();
                int op1 = pop(); 
                
            switch (exp[i])
            {
            case '+':
                push(op1 + op2);
                break;

            case '-':
                push(op1 - op2);
                break;

            case '*':
                push(op1 * op2);
                break;
            
            case '/':
                push(op1/op2);
                break;

            default:
                printf("Operator Error.");
                return 0;
            }
        }
        else push(exp[i] - '0');
    }
    return pop(); 
}

void main(){
    char inpstr[] = "23*54*+9+";
    int result = EvaluatePostfix(inpstr);     
    printf("%d", result);
}