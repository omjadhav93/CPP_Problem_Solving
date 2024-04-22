/* Write a C program ro reverse the elements in given range in sorted list.
    Example..
    Input : 10
            9 1 2 4 3 4 6 7 8 10
            3 8

    Output : 1 2 8 7 6 4 4 3 9 10

    Explaination : The sorted list of given array elements is 1 2 3 4 4 6 7 8 9 10 , after reversing the elements with in range 3 and 8 we get 1 2 8 7 6 4 4 3 9 10.

*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                swap(&arr[i], &arr[j]);
        }
    }
}

void reverseRange(int *arr, int a, int b, int n)
{
    int low = 0, high = n - 1;
    while (a > arr[low])
        low++;
    while (b < arr[high])
        high--;
    while (low < high){
        swap(&arr[low],&arr[high]);
        low++;
        high--;
    }
}

int main(){
    int arr[20],n,i,a,b;

    printf("Enter No. of Elements(<20) : ");
    scanf("%d",&n);

    printf("Enter %d Elements : ",n);
    for (i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    // Sorting
    selectionSort(arr,n);

    printf("Enter Range For Reverse The List : ");
    scanf("%d %d",&a,&b);

    // Reversing In Range
    reverseRange(arr,a,b,n);

    // Print Answer
    for (int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}