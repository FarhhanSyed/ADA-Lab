#include <stdio.h>
#include <stdlib.h>
int knap[100][100], w[100], p[100], n, m, i, j;
int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsack()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                knap[i][j] = 0;
            }
            else if (j < w[i - 1])
            {
                knap[i][j] = knap[i - 1][j];
            }
            else
            {
                knap[i][j] = max(knap[i - 1][j], p[i - 1] + knap[i - 1][j - w[i - 1]]);
            }
        }
    }
    return knap[n][m];
}
int main()
{
    printf("Enter number of items:\n");
    scanf("%d", &n);
    printf("Enter sack capacity:\n");
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
    {
        printf("Enter weight:");
        scanf("%d", &w[i]);
        printf("Enter profit:");
        scanf("%d", &p[i]);
    }
    printf("MAXIMUN:%d\n", knapsack());
    printf("Adjacency:");
    for (int i = 0; i <= n; i++)

    {
        for (int j = 0; j <= m; j++)
        {
            printf("%d ", knap[i][j]);
        }
        printf("\n");
    }
}
