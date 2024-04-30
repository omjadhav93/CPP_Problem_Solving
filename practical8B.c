/*
    Write a c program to sort elements in row wise and print the elements of matrix in Column major order.
*/

#include <stdio.h>

void insertionSort(int *arr, int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        int insert = arr[i];
        while (j >= 0 && arr[j] > insert)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = insert;
    }
}

int main()
{

    int m, n;
    printf("Enter order of matrix : ");
    scanf("%d %d", &m, &n);

    int arr[m][n];

    printf("Enter elements of matrix : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        // Sort Each Row
        insertionSort(arr[i], n);
    }

    printf("Required Output : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[j][i]);
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
    Required Output : 
    1 7 2 
    2 8 3 
    3 9 5 
    4 10 6 
*/