#include <stdio.h>

int main() {
    int alloc[10][10], max[10][10];
    int avail[10], work[10], total[10];
    int need[10][10];
    int finish[10];
    int safeSeq[10];

    int i, j, k, n, m;
    int count = 0;

    printf("Enter number of processes and resources: ");
    scanf("%d%d", &n, &m);

    // Initialize finish array
    for (i = 0; i < n; i++)
        finish[i] = 0;

    // Input max matrix
    printf("Enter the MAX matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Input allocation matrix
    printf("Enter the ALLOCATION matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Input total resources
    printf("Enter total resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &total[i]);

    // Calculate available resources
    for (i = 0; i < m; i++) {
        avail[i] = 0;
        for (j = 0; j < n; j++) {
            avail[i] += alloc[j][i];
        }
        avail[i] = total[i] - avail[i];
        work[i] = avail[i];
    }

    // Calculate need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's Algorithm
    while (count < n) {
        int found = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int canExecute = 1;

                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = 0;
                        break;
                    }
                }

                if (canExecute) {
                    // Add allocated resources to work
                    for (k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;

                    printf("Process P%d executed\n", i);
                }
            }
        }

        if (!found) {
            printf("\nSystem is NOT in safe state (Deadlock possible)\n");
            return 0;
        }
    }

    // Print safe sequence
    printf("\nSystem is in SAFE state\nSafe sequence: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);

    printf("\n");

    return 0;
}