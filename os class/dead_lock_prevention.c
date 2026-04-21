#include <stdio.h>

int main() {
    char job[10][10];
    int time[10], temp[10], index[10];
    int safe[10];
    int avail;
    int i, j, n, t;
    int count = 0;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    // Input job name and time
    for (i = 0; i < n; i++) {
        printf("Enter job name and time: ");
        scanf("%s %d", job[i], &time[i]);
    }

    printf("Enter available resource: ");
    scanf("%d", &avail);

    // Copy time into temp array and store indices
    for (i = 0; i < n; i++) {
        temp[i] = time[i];
        index[i] = i;
    }

    // Sort jobs based on time (Shortest Job First)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                // swap time
                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;

                // swap index
                t = index[i];
                index[i] = index[j];
                index[j] = t;
            }
        }
    }

    // Check safe sequence
    for (i = 0; i < n; i++) {
        int q = index[i];

        if (time[q] <= avail) {
            safe[count++] = q;
            avail -= time[q];
        } else {
            printf("\nNo safe sequence possible\n");
            return 0;
        }
    }

    // Print safe sequence
    printf("\nSafe sequence is:\n");
    for (i = 0; i < count; i++) {
        printf("%s (%d)\n", job[safe[i]], time[safe[i]]);
    }

    return 0;
}