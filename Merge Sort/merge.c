#include <stdio.h>
#include <stdlib.h>
void merge(int *A, int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = l; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void mergesort(int *A, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergesort(A, l, mid);
        mergesort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}
int main()
{
    int n;
    printf("Enter size:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
