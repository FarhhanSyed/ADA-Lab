#include <stdio.h>
#include <stdlib.h>
int graph[100][100], visited[100];
int count = 0, op_count = 0, dfscount = 0;
int cycle = 1;

void dfs(int n, int start, int parent)
{
    visited[start] = 1;
    count++;
    printf("-->%c", start + 65);
    for (int i = 0; i < n; i++)
    {
        op_count++;
        if (graph[start][i] && i != parent && visited[i])
        {
            cycle = 1;
        }
        if (graph[start][i] && (visited[i] == 0))
        {
            dfs(n, i, start);
        }
    }
}
int main()
{
    int n, dfscount = 0;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    printf("Enter Adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0;
    }
    printf("The matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("DFS::\n");
    dfscount++;
    dfs(n, 0, -1);
    printf("\n");
    if (count == 0)
    {
        printf("The graph is connected.\n");
    }
    else
    {
        printf("The graph is not connected.\n");
        int start = 1;
        while (count != n)
        {
            if (visited[start] != 1)
            {
                printf("\n");
                dfs(n, start, -1);
                dfscount++;
            }
            start++;
        }
    }
    printf("The number of components:%d\n", dfscount);
    if (cycle)
    {
        printf("The graph is cyclic\n");
    }
    else
    {
        printf("The graph is acyclic\n");
    }
}
