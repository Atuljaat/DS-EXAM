#include <stdio.h>

void printArray (int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
}

void selectionSort (int arr[] , int size){
    // Time Complexity => O(n^2) in every scenario
    for (int i = 0; i < size-1; i++)
    {
        int lowest = i ;
        for (int j = i + 1; j < size ; j++)
        {
            if (arr[lowest] > arr[j]){
                lowest = j;
            }
        }
        if (lowest != i ){
            int temp = arr[lowest];
            arr[lowest] = arr[i];
            arr[i] = temp; 
        }
    }
}

void bubbleSort (int arr[], int size){
    // for (int i = 0; i < size - 1 ; i++)
    // {
    //    for (int j = 0 ; j < size - i -1; j++)
    //    {
    //      if ( arr[j] > arr[j+1]){
    //         int temp = arr[j];
    //         arr[j] = arr[j+1];
    //         arr[j+1] = temp;
    //      }
    //    }
       
    // }

    for (int i = 0; i < size - 1; i++)
    {
        int swap = 0 ;
       for (int j = 0; j < size - 1 - i; j++)
       {
            if (arr [j] > arr[j+1] ){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = 1;
            }
       }
       if (swap == 0 ){
        break;
       }
    }
    
}

void insertionSort (int arr[] , int size){
    for (int i = 1 ; i < size ; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {5,4,3,2,1};
    // int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,size);
    printArray(arr,size);
}