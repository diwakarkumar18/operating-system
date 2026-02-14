#include <stdio.h>
/*
int main() 
{
    int bt[20], wt[20], tat[20];
    int i, n;
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes -- ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    // First process
    wt[0] = 0;
    tat[0] = bt[0];

    // Remaining processes
    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];

        wtavg += wt[i];
        tatavg += tat[i];
    }

    tatavg += tat[0];  // include first process

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", wtavg / n);
    printf("\nAverage Turnaround Time = %.2f\n", tatavg / n);

    return 0;
}
*/
#include <stdio.h>

int main()
{
    int at[20], bt[20], wt[20], tat[20], ct[20];
    int i, j, n;
    int temp;

    float wtavg = 0, tatavg = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    // Sort according to Arrival Time (Simple Bubble Sort)
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(at[i] > at[j])
            {
                // swap arrival time
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // First process
    ct[0] = at[0] + bt[0];
    wt[0] = 0;
    tat[0] = bt[0];

    // Remaining processes
    for(i = 1; i < n; i++)
    {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];  // CPU Idle case
        else
            ct[i] = ct[i-1] + bt[i];

        wt[i] = ct[i] - at[i] - bt[i];
        tat[i] = ct[i] - at[i];

        wtavg += wt[i];
        tatavg += tat[i];
    }

    tatavg += tat[0];

    // Output Table
    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", wtavg/n);
    printf("\nAverage Turnaround Time = %.2f\n", tatavg/n);

    // Gantt Chart
    printf("\nGantt Chart:\n|");
    for(i = 0; i < n; i++)
        printf(" P%d |", i);

    printf("\n%d", at[0]);
    for(i = 0; i < n; i++)
        printf("    %d", ct[i]);

    return 0;
}
