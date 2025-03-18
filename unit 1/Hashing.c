#include <stdio.h>
void printArray (int *arr , int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

void divisionHashing (int arr[] , int hasharray[] , int size) {
    for (int i = 0; i < size; i++)
    {
        hasharray[arr[i] % 7] = arr[i];
    }
}
void searchIntoDivisionHashing (int hasharray[] , int number ){
    int index = number % 7;
    printf("%d is at the index %d\n", hasharray[index] , index);
}

int main (){
    int arr[] = {10, 22, 35, 47, 58};
    int hashedArray[7] = {0,0,0,0,0,0,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);
    // divisionHashing(arr,hashedArray,size);
    // searchIntoDivisionHashing(hashedArray,47);
    printArray(hashedArray,7);

}