#include <stdio.h>

void printArray (int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

void merge (int arr[] , int low , int mid , int high){
    int tempArray[high-low+1];
    int k = 0 ;
    int left = low ;
    int right = mid + 1;
    while ( left <= mid && right <= high ){
        if (arr[left] >= arr[right]){
            tempArray[k] = arr[right];
            right++;
            k++;
        } else {
            tempArray[k] = arr[left];
            left++;
            k++;
        }
    }

    while (left <= mid ){
        tempArray[k] = arr[left];
        left++;
        k++;
    }
    
    while (right <= high ){
        tempArray[k] = arr[right];
        right++;
        k++;
    }

    // copying the temp array into original

    for (int i = low; i <= high; i++)
    {
        arr[i] = tempArray[i - low];
    }
}

void mergeSort (int arr[] , int low , int high){
    if (low >= high) return ; 
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}



int main(){
    int arr[] = {5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    printArray(arr,size);
}