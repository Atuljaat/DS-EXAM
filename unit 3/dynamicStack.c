#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void push () {
    struct node *box = (struct node *)malloc(sizeof(struct node));

    if (box == NULL){
        printf("memory allocation fail\n");
        return;
    }

    box->next = NULL;
    printf("Enter the data in the node : ");
    scanf("%d",&box->data);

    if (start == NULL){
        start = box;
    } else {
        struct node *temp = start;
        start = box;
        box->next = temp;
    }
}

void pop () {
    if (start == NULL){
        printf("Stack doesnt exist \n");
    } else if (start->next == NULL) {
        free(start);
    } 
    else {
        struct node *temp = start->next;
        free(start);
        start = temp;
    }
}

void print (){
    if (start == NULL){
        printf("Stack is empty\n");
    } else {
        struct node *temp = start;
        while (temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int input;
    while (1)
    {
        printf("What you want to do : \n");
        printf("1.Push\n2.Pop\n3.Print\n4.Exit\n");
        scanf("%d",&input);
        switch (input){
            case 1 : push();
            break;

            case 2 : pop();
            break;

            case 3 : print();
            break;

            case 4 : return 1;
            break;

            default : printf("Invalid Choice \n");
        }
    }
}