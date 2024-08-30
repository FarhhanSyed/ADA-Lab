#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *A, int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    while (i <= j)
    {
        do
        {
            i++;
        } while (A[i] < pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i <= j)
        {
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[j], &A[l]);
    return j;
}

void quick(int *A, int l, int h)
{
    if (l < h)
    {
        int k = partition(A, l, h);
        quick(A, l, k - 1);
        quick(A, k + 1, h);
    }
}

int main()
{
    int n;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter elements:");
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quick(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
