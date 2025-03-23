#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *end = NULL;

void enQueue () {
    struct node *box = (struct node *)malloc(sizeof(struct node));
    if (box == NULL){
        printf("Memory allocation failed \n");
    }
    
    printf("Enter the data : ");
    scanf("%d",&box->data);
    box->next = NULL;
    if (start == NULL){
        start = box;
        end = box;
    } else {
        end->next = box;
        end = box;
    }
}

void deQueue () {
    if (start == NULL){
        printf("Queue doesnt exist\n");
    } else {
        struct node *temp = start->next;
        free(start);
        start = temp;
    }
}

void print (){
    if (start == NULL){
        printf("Queue is empty\n");
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

int main () {
    int input;
    while (1)
    {
        printf("What you want to do : \n");
        printf("1.Enqueue\n2.Dequeue\n3.Print\n4.Exit\n");
        scanf("%d",&input);
        switch (input){
            case 1 : enQueue();
            break;

            case 2 : deQueue();
            break;

            case 3 : print();
            break;

            case 4 : return 1;
            break;

            default : printf("Invalid Choice \n");
        }
    }
}