#include <stdio.h>

int main() {
    int n, tq;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], wt[n], tat[n], ct[n];
    int i, time = 0, remain = 0;
    float avg_wt = 0, avg_tat = 0;

    // Input Arrival Time and Burst Time
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    // Loop until all processes finish
    while(remain > 0) {
        int done = 1; // check if any process executed

        for(i = 0; i < n; i++) {
            // process should have arrived and not finished
            if(rt[i] > 0 && at[i] <= time) {
                done = 0;

                if(rt[i] <= tq) {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;

                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    avg_tat += tat[i];
                    avg_wt += wt[i];

                    remain--;
                } else {
                    rt[i] -= tq;
                    time += tq;
                }
            }
        }

        // If no process is ready, move time forward
        if(done == 1) {
            time++;
        }
    }

    // Output
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}