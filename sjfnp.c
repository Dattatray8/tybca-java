#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<time.h>

void cal(int n, int arr[], int burst[], int process[]) {
    int ct[n], tat[n], wt[n], currentTime = 0, completed = 0, i;
    bool isCompleted[n];
    float totalTat = 0, totalWt = 0;

    for (i = 0; i < n; i++) {
        isCompleted[i] = false;
    }

    printf("\nGantt chart:\n");

    while (completed < n) {
        int idx = -1, minBt = INT_MAX;

        for (i = 0; i < n; i++) {
            if (arr[i] <= currentTime && !isCompleted[i] && burst[i] < minBt) {
                minBt = burst[i];
                idx = i;
            }
        }

        if (idx != -1) {
            printf("P%d(%d-%d)\n", process[idx], currentTime, currentTime + burst[idx]);

            currentTime += burst[idx];
            ct[idx] = currentTime;
            tat[idx] = ct[idx] - arr[idx];
            wt[idx] = tat[idx] - burst[idx];
            isCompleted[idx] = true;   // Mark process as completed
            completed++;               // Increment completed count

            totalTat += tat[idx];
            totalWt += wt[idx];
        } else {
            currentTime++;  // No process available, idle time
        }
    }

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", process[i], arr[i], burst[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT: %.2f", totalTat / n);
    printf("\nAverage WT : %.2f\n", totalWt / n);
}

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arr[n], burst[n], process[n];

    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d%d", &arr[i], &burst[i]);
    }

    cal(n, arr, burst, process);
    return 0;
}
