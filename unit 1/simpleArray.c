#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertAtStart(int arr[], int size, int element)
{
    for (int i = size - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = element;
}

void insertAtPoint(int arr[], int size, int position, int element)
{
    for (int i = size - 2; i >= position; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
    // for eg : arr[4] = {5,4,3,0} here i = 2 ,  position= 1
    // 1 iteration : {5,4,3,3}
    // 2 iteration : {5,4,4,3}
    // after making space we shift the array : {5,element,4,3}
}

void deleteAtPoint(int arr[], int size, int position)
{
    for (int i = position; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
        arr[i + 1] = 0;
    }
}

void linearSearch(int arr[], int size, int number)
{
    //  simple search
    //  complexity => best = O(1)
    //                    avg = O(n)
    //                    worst = O(n)
    int isPresent = 0;
    for (int i = 0; i < size; i++)
    {
        if (number == arr[i])
        {
            printf("Number %d found at index %d\n", number, i);
            isPresent = 1;
        }
    }
    if (isPresent == 0)
    {
        printf("Number nhi mila");
    }
}

void binarySearch(int arr[], int size, int number)
{
    // we need a sorted array to do this
    // Complexity => best = O(1)
    //              avg = O(logn)
    // worst = O(logn)
    // 1,000,000,000 elements mai linear search lega 1,000,000,000 steps aur binary lega 30 steps
    int first = 0;
    int end = size - 1;
    int mid = (first + end) / 2;
    int isPresent = 0;

    while (first <= end)
    {
        mid = (first + end) / 2;
        if (number == arr[mid])
        {
            printf("Number is found at index %d", mid);
            isPresent = 1;
            break;
        }
        else
        {
            if (number < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                first = mid + 1;
            }
        }
    }
    if (isPresent == 0)
    {
        printf("Number is not found");
    }
}

void mergeArrayUnsorted (int arr1[] , int arr2[] , int size1 , int size2){
    int arr3 [size1 + size2 ];
    int index = 0 ;

    // loop foir first array to copy into the 3rd array
    for (int i = 0; i < size1; i++)
    {
        arr3[index] = arr1[i];
        index++;
    }

    // loop for second array to copy into 3rd array
    for (int i = 0; i < size2; i++)
    {
        arr3[index] = arr2[i];
        index++;
    }
    int size = sizeof(arr3)/sizeof(arr3[0]);
    printArray(arr3,size);
}

void mergeArraySorted (int arr1[],int arr2[],int size1 , int size2){
    int index = 0;
    
    
}

int main()
{
    int array[] = {1, 2, 3};
    int array2[] = { 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(array[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    printf("%d\n", size - 1);
    // insertAtStart(array,size,6);
    // insertAtPoint(array,size,1,0);
    // deleteAtPoint(array,size,1);
    // binarySearch(array, size, 4);
    // mergeArrayUnsorted(array,array2,size,size2);
    // printArray(array, size);
}
