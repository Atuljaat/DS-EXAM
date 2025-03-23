#include <stdio.h>
int start = -1;

void enQueue (int queue[]){
    int input;
    printf("Enter the value : ");
    scanf("%d",&input);
    queue[++start] = input;
    printf("%d is queued\n",input);
}

void deQueue (int queue[]){
    if (start == -1 ){
        printf("Queue doesnt exist\n");
    } else {
        printf("%d is dequeue\n",queue[start]);
        queue[start] = 0;
        start--;
    }
}

void print(int queue[] , int size){
    if ( start == -1){
        printf("queue doesnt exist \n");
    } else {
        for (int i = 0; i <= start; i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}


int main (){
    int size , input;
    printf("Enter the size of the Queue : ");
    scanf("%d",&size);
    int queue[size];
    while (1)
    {
        printf("What you want to do : \n");
        printf("1.Enqueue\n2.Dequeue\n3.Print\n4.Exit\n");
        scanf("%d",&input);
        switch (input){
            case 1 : enQueue(queue);
            break;

            case 2 : deQueue(queue);
            break;

            case 3 : print(queue,size);
            break;

            case 4 : return 1;
            break;

            default : printf("Invalid Choice \n");
        }
    }
    
}