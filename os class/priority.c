#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n];
    int rt[n], ct[n], tat[n], wt[n];
    int i, time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    // Input
    for(i = 0; i < n; i++) {
        printf("Enter AT, BT, Priority for P%d: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i]; // remaining time
    }

    // Process until all complete
    while(completed < n) {
        int idx = -1;
        int highest_priority = 9999;

        // Find highest priority process
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            // Execute for 1 unit time
            rt[idx]--;
            time++;

            // If process completes
            if(rt[idx] == 0) {
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];

                avg_tat += tat[idx];
                avg_wt += wt[idx];

                completed++;
            }
        } else {
            // CPU idle
            time++;
        }
    }

    // Output
    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("Average Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}