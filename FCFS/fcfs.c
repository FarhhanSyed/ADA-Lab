#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int id;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
    int response;
} Process;

void fcfs(Process processes[], int n);
int main()
{
    int n;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    Process processes[n];
    for (int i = 0; i < n; i++)
    {
        printf("Process:%d\n", i + 1);
        printf("Enter arrival time:\n");
        scanf("%d", &processes[i].arrival);
        printf("Enter burst time:\n");
        scanf("%d", &processes[i].burst);
        processes[i].id = i + 1;
        printf("\n");
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (processes[j].arrival > processes[j + 1].arrival)
            {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    fcfs(processes, n);
    return 0;
}

void fcfs(Process processes[], int n)
{
    int elapsed = 0;
    int totalturnaround = 0;
    int totalwaiting = 0;
    int totalresponse = 0;
    float avgturnaround = 0;
    float avgresponse = 0;
    float avgwaitaing = 0;
    printf("\nGANTT CHART\n");
    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrival > elapsed)
            elapsed = elapsed + (processes[i].arrival - elapsed);

        int temp = elapsed;
        processes[i].response = elapsed - processes[i].arrival;
        elapsed = elapsed + processes[i].burst;
        processes[i].completion = elapsed;
        processes[i].turnaround = processes[i].completion - processes[i].arrival;
        processes[i].waiting = processes[i].turnaround - processes[i].burst;
        printf("|(%d) P%d (%d)|", temp, processes[i].id, elapsed);
    }
    printf("\n");
    printf("Observation Table:\n");
    printf("PID\tAT\tBT\tCT\tTT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].arrival, processes[i].burst, processes[i].completion, processes[i].turnaround, processes[i].waiting, processes[i].response);
        totalturnaround += processes[i].turnaround;
        totalwaiting += processes[i].waiting;
        totalresponse += processes[i].response;
    }
    avgturnaround = (float)totalturnaround / n;
    avgwaitaing = (float)totalwaiting / n;
    avgresponse = (float)totalresponse / n;
    printf("AVG turnaround:%.2f\n", avgturnaround);
    printf("AVG Waiting:%.2f\n", avgwaitaing);
    printf("AVG Response:%.2f\n", avgresponse);
}
