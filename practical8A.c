/*
    Write a c program to sort in ascending order and reverse the individual row elements of an m x n matrix.
*/

#include <stdio.h>

void insertionSort(int *arr,int n){
    int i,j;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        int insert = arr[i];
        while (j >= 0 && arr[j] > insert)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = insert;
    }
}

void reverseList(int *arr,int n){
    int i = 0,j = n-1;
    while (i<j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;j--;
    }
}

int main(){
    
    int m,n;
    printf("Enter order of matrix : ");
    scanf("%d %d",&m,&n);

    int arr[m][n];
    
    printf("Enter elements of matrix : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
        // Sort Each Row
        insertionSort(arr[i],n);
        reverseList(arr[i],n);
    }

    printf("Required Matrix : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
    Enter order of matrix : 3 4
    Enter elements of matrix : 
    1 4 2 3
    7 8 10 9
    6 3 5 2
    Required Matrix : 
    4 3 2 1 
    10 9 8 7 
    6 5 3 2 
*/