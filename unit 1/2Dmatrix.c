#include <stdio.h>

void RowMajorAndColumnMajor () {
    // Row Major
    // Address(A[i][j])=Base Address+(i×n+j)×Size

    // Column Major
    // Address(A[i][j])=Base Address+(j×m+i)×Size

};

void print2DArray (int arr[3][3] , int rows , int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void transposeArraySquare (int arr[3][3] , int rows , int cols){
    int arr3[3][3];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
           arr3[j][i] = arr[i][j]; 
        }
    }
    print2DArray(arr,3,3);
    print2DArray(arr3,3,3);
}

void add2SquareArray (int arr1[3][3] , int arr2[3][3] , int rows , int cols){
    int arr3[3][3];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    print2DArray(arr3,3,3);
}

void subtract2SquareArray (int arr1[3][3] , int arr2[3][3] , int rows , int cols){
    int arr3[3][3];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr3[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    print2DArray(arr3,3,3);
}

void multiply2SquareArray (int arr1[3][3] , int arr2[3][3] , int rows , int cols){
    int arr3[3][3];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int sum = 0;
            for (int k = 0; k < rows; k++)
            {   
                sum = sum + (arr1[i][k] * arr2[k][j]);
            }
            arr3[i][j] = sum;
        }
    }
    print2DArray(arr3,3,3);
}

void multiply2UnequalArray (int arr1[3][2] , int arr2[2][3] , int rows1 , int cols1 , int rows2 , int cols2){
    int arr3[3][3];
    for (int i = 0; i < rows1; i++) // rows of first
    {
        for (int j = 0; j < cols2; j++) // cols of second
        {
            int sum = 0;
            for (int k = 0; k < cols1; k++) // either 1st cols and 2nd rows about are same 
            {   
                sum = sum + (arr1[k][j] * arr2[i][k]);
            }
            arr3[i][j] = sum;
        }
    }
    print2DArray(arr3,3,3);
}

void lowerTriangluarMatrix (int arr[],int rows){
    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if ( j < i ) {
                printf("%d ",arr[index]);
                index++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void upperTriangularMatrix (int arr[] , int rows){
    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if ( j < i ){
                printf("0 ");
            } else {
                printf("%d ",arr[index]);
                index++;
            }
        }
        printf("\n");   
    }
}

void sparseIntoTuple (int arr[4][4] , int rows , int cols , int nonZero){
    int tupleMatrix[nonZero+1][3];
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if ( arr[i][j] != 0 ){
              tupleMatrix[k][0] = i;
              tupleMatrix[k][1] = j;
              tupleMatrix[k][2] = arr[i][j];
              k++;
            }
        }
    }

    // printing the tuple matrix
    for (int i = 0; i < nonZero+1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            printf("%d %d  %d \n",tupleMatrix[i][j] , tupleMatrix[i][j+1],tupleMatrix[i][j+2]);
        }
    }
    
}

int main (){
    int array1[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}    
    };
    int array2[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}    
    };

    transposeArraySquare(array1,3,3);

    int array3[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    int sparse1D[] = {1,2,3,4,5,6};
    int sparse2D[4][4] = {
        {0,0,0,4},
        {1,0,0,2},
        {0,8,0,0},
        {0,2,0,0}
    };
    int tuple1[5][4] = {
        {1,2,10},
        {1,4,12},
        {3,3,5},
        {4,1,15},
        {4,2,15}
    };
    int tuple2[5][4] = {
        {1,3,8},
        {2,4,23},
        {3,3,9},
        {4,1,20},
        {4,2,25}
    };
    // sparseIntoTuple(sparse2D,4,4,5);
    // upperTriangularMatrix(sparse1D,3);
    // transposeArraySquare(array1,3,3);
    // print2DArray(array1,3,3);
}