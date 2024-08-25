#include <stdio.h>
#include <stdlib.h>
int graph[100][100], visited[100];
int count = 0, dfscount = 0, op_count = 0;
int cycle = 0;
void dfs(int n, int start, int parent)
{
    visited[start] = 1;
    count++;
    for (int i = 0; i < n; i++)
    {
        op_count++;
        if (i != parent && graph[start][i] && visited[i])
            cycle = 1;
        if (graph[start][i] && (visited[i] == 0))
        {
            dfs(n, i, start);
        }
    }
}
void plotter(int k)
{
    int v;
    FILE *f1, *f2;
    f1 = fopen("dfs_b.txt", "a");
    f2 = fopen("dfs_w.txt", "a");
    for (int i = 1; i <= 10; i++)
    {
        v = i;
        if (k == 0)
        {
            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    if (i == j)
                    {
                        graph[i][j] = 0;
                    }
                    else
                    {
                        graph[i][j] = 1;
                    }
                }
                visited[i] = 0;
            }
        }
        if (k == 1)
        {
            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    graph[i][j] = 0;
                }
                visited[i] = 0;
            }
            for (int i = 0; i < v - 1; i++)
            {
                graph[i][i + 1] = 1;
            }
        }
        cycle = 0, op_count = 0, dfscount = 0, count = 0;
        dfscount++;
        dfs(v, 0, -1);

        int start = 1;
        while (count != v)
        {
            if (visited[start] != 1)
            {
                dfs(v, start, -1);
                dfscount++;
            }
            start++;
        }
        if (k == 0)
        {
            fprintf(f2, "%d\t%d\n", v, op_count);
        }
        else
        {
            fprintf(f1, "%d\t%d\n", v, op_count);
        }
    }
    fclose(f1);
    fclose(f2);
}

void main()
{
    for (int i = 0; i < 2; i++)
    {
        plotter(i);
    }
    printf("Data entered into the file\n");
}