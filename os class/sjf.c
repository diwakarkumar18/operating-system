#include<stdio.h>

int main() 
{
    int n, i, time = 0, count = 0, shortest;
    int at[20], bt[20], rt[20];
    int wt[20], tat[20], ct[20];
    int min, finish_time;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) 
    {
        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];   // Remaining time
    }

    rt[19] = 9999;  // Sentinel value

    while(count != n) 
    {
        min = 9999;
        shortest = 19;

        for(i = 0; i < n; i++) 
        {
            if(at[i] <= time && rt[i] < min && rt[i] > 0) 
            {
                min = rt[i];
                shortest = i;
            }
        }

        rt[shortest]--;
        min = rt[shortest];

        if(rt[shortest] == 0) 
        {
            count++;
            finish_time = time + 1;
            ct[shortest] = finish_time;
            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            tat[shortest] = finish_time - at[shortest];

            total_wt += wt[shortest];
            total_tat += tat[shortest];
        }
        time++;
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT");
    for(i = 0; i < n; i++) 
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);

    return 0;
}