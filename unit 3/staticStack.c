#include <stdio.h>
int top = -1;

void push ( int stack[],int size) {
    int no;
    printf("Enter the Number you want to push : ");
    scanf("%d",&no);
    if ( top == size - 1){
        
        printf("Stack is full\n");
    } else {
        stack[++top] = no;
        printf("%d is pushed\n",stack[top]);
    }
}

void pop(int stack[],int size){
    if ( top == -1 ){
        printf("Stack doesnt exist");
    } else {
        printf("%d is popped\n",stack[top]);
        stack[top] = 0;
        top--;
    }
}

void print(int stack[] , int size){
    for (int i = top; i >= 0 ; i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main (){
    int size;
    printf("Enter the size of the stack you want : ");
    scanf("%d",&size);
    int stack[size];
    int input;
    while (1)
    {
        printf("What you want to do : \n");
        printf("1.Push\n2.Pop\n3.Print\n4.Exit\n");
        scanf("%d",&input);
        switch (input){
            case 1 : push(stack,size);
            break;

            case 2 : pop(stack,size);
            break;

            case 3 : print(stack,size);
            break;

            case 4 : return 1;
            break;

            default : printf("Invalid Choice \n");
        }
    }
    
}