#include<stdio.h>
#include<stdlib.h>

int adj[10][10], topo[10], indegree[10], visited[10];
int front, rear, count, queue[10];

void reset(int vertices) {
    front = 0;
    rear = -1;
    count = 0;

    for (int i = 0; i < vertices; i++) {
        indegree[i] = 0;
        visited[i] = 0;
    }
}

void calculateIndegree(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (adj[j][i] == 1)
                indegree[i]++;
        }
        if (indegree[i] == 0) {
            rear = (rear + 1) % vertices;
            queue[rear] = i;
            visited[i] = 1;
            count++;
        }
    }
}

void removeSourceVertices(int vertices) {
    int processed = 0;
    while (count != 0) {
        int src = queue[front];
        front = (front + 1) % vertices;
        topo[processed++] = src;
        count--;

        for (int i = 0; i < vertices; i++) {
            if (adj[src][i] == 1)
                indegree[i]--;
            if (indegree[i] == 0 && visited[i] == 0) {
                rear = (rear + 1) % vertices;
                queue[rear] = i;
                visited[i] = 1;
                count++;
            }
        }
    }
    if (processed != vertices) {
        printf("Cycles exist, no topological sorting possible\n");
    } else {
        printf("The topological sorting is:\n");
        for (int i = 0; i < vertices; i++)
            printf("%c\t", topo[i] + 65);
    }
}

int main() {
    int n;
    printf("Enter number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nAdjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }

    reset(n);
    calculateIndegree(n);
    removeSourceVertices(n);

    printf("\n");

    return 0;
}
