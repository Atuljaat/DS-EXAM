#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ;
    struct node *next;
};

struct node *start = NULL;

void createSingleLinkList () {
    struct node *box = (struct node *)malloc(sizeof(struct node));
    if (box == NULL ) {
        printf("Memory Allocation failed \n");
        return;
    }

    printf("Enter the data : ");
    scanf("%d",&box->data);
    box->next = NULL;

    if (start == NULL) {
        start = box;
    } else {
        struct node *ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = box;
    }
}

void ModifyInLinkListbyData () {
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    if (start == NULL){
        printf("Linklist doesnt exist");
    } else {
        struct node *ptr = start;
        while ( ptr->next != NULL && ptr->data != num)
        {
            ptr = ptr->next;
        }

        if (ptr == NULL){
            printf("Value doesnt exist");
            return;
        }

        printf("Enter the new Value");
        scanf("%d",&ptr->data);
        printf("Value updated Successfully");
    }
}

void deleteInLinkList () {
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    if (start == NULL){
        printf("Linklist doesnt exist");
    } else if (start->data == num){
        struct node *ptr = start->next;
        free(start);
        start = ptr;
    }
    else {
        struct node *ptr = start;
        struct node *prev = NULL;

        while ( ptr->next != NULL && ptr->data != num)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        
        if (ptr == NULL){
            printf("number doesnt exist in the linklist");
            return;
        }
        
        prev->next = ptr->next;
        free(ptr);
    }
}

void transverseLinkList () {
    printf("\n");
    if (start == NULL){
        printf("Linklist doesnt exist");
        return;
    }

    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void searchInLinkList () {
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    if (start == NULL){
        printf("Linklist doesnt Exist");
        return;
    } 
    struct node *ptr = start;
    while (ptr->data != num)
    {
        ptr = ptr->next;
    }
    printf("number %d is found at address %p",ptr->data , ptr);
}

void reverseLinkList () {
    if (start == NULL){
        printf("List doesnt exist");
        return;
    }

    struct node *prev = NULL;
    struct node *curr = start;
    struct node *next = NULL;

    while (curr != NULL) {
       next = curr->next;
       curr->next = prev;
       prev = curr;
       curr = next;
    }

    start = prev;  // Update head
    
}



int main () {
    printf("Welcome to this program\n");
    int input;
    while (input)
    {
        printf("\n1.Enter Value \n2.Modify Value\n3.Delete Value\n4.Exit\n5.Transverse List\n6.Search List\n7.Reverse List\n");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            createSingleLinkList();
            break;
        
        case 2 : 
            ModifyInLinkListbyData();
            break;
        
        case 3 : 
            deleteInLinkList();
            break;
        
        case 4 : 
        return 0;
        break;

        case 5 : 
        transverseLinkList();
        break;

        case 6 :
        searchInLinkList();
        break;
        
        case 7 :
        reverseLinkList();
        break;

        default:
            break;
        }
    }
    
}