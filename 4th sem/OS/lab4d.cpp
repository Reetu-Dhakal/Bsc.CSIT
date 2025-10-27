#include <stdio.h>

struct process {
    int id, AT, BT, WT, TAT;
};

struct process a[10];

// Queue implementation
int queue[100];
int front = -1, rear = -1;

void insert(int n) {
    if (front == -1) front = 0;
    rear++;
    queue[rear] = n;
}

int delete() {
    int n = queue[front];
    front++;
    return n;
}

int main() {
    int n, TQ, p, TIME = 0;
    int temp[10], exist[10] = {0};
    float total_wt = 0, total_tat = 0, Avg_WT, Avg_TAT;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].AT, &a[i].BT);
        a[i].id = i;
        temp[i] = a[i].BT;
    }

    printf("Enter the Time Quantum: ");
    scanf("%d", &TQ);

    // Insert all processes that arrive at time 0
    for (int i = 0; i < n; i++) {
        if (a[i].AT == 0) {
            insert(i);
            exist[i] = 1;
        }
    }

    while (front <= rear) {
        p = delete();

        if (a[p].BT >= TQ) {
            a[p].BT -= TQ;
            TIME += TQ;
        } else {
            TIME += a[p].BT;
            a[p].BT = 0;
        }

        // Check new arrivals up to current TIME
        for (int i = 0; i < n; i++) {
            if (exist[i] == 0 && a[i].AT <= TIME) {
                insert(i);
                exist[i] = 1;
            }
        }

        if (a[p].BT == 0) {
            a[p].TAT = TIME - a[p].AT;
            a[p].WT  = a[p].TAT - temp[p];
            total_tat += a[p].TAT;
            total_wt  += a[p].WT;
        } else {
            insert(p); // put back if not finished
        }
    }

    Avg_TAT = total_tat / n;
    Avg_WT  = total_wt / n;

    printf("\nID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", a[i].id, a[i].AT, temp[i], a[i].WT, a[i].TAT);
    }
    printf("\nAverage Waiting Time = %.2f\n", Avg_WT);
    printf("Average Turnaround Time = %.2f\n", Avg_TAT);

    return 0;
}
