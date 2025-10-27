#include<stdio.h>
#define INF 999999

struct process {
    int WT, AT, BT, TAT;
};

struct process a[10];

int main() {
    int n, temp[10];
    int count=0, t=0, short_P;
    float total_WT=0, total_TAT=0, Avg_WT, Avg_TAT;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("Enter Arrival Time and Burst Time of each process:\n");
    for(int i=0;i<n;i++) {
        scanf("%d%d",&a[i].AT,&a[i].BT);
        temp[i] = a[i].BT;  // store original BT
    }

    while(count != n) {
        short_P = -1;
        int min_BT = INF;

        // find process with smallest remaining BT
        for(int i=0;i<n;i++) {
            if(a[i].AT <= t && a[i].BT > 0 && a[i].BT < min_BT) {
                min_BT = a[i].BT;
                short_P = i;
            }
        }

        if(short_P == -1) {
            t++; // no process available, just move time forward
            continue;
        }

        a[short_P].BT--;

        // process completed
        if(a[short_P].BT == 0) {
            count++;
            a[short_P].WT = t+1 - a[short_P].AT - temp[short_P];
            a[short_P].TAT = t+1 - a[short_P].AT;
            total_WT += a[short_P].WT;
            total_TAT += a[short_P].TAT;
        }
        t++;
    }

    Avg_WT = total_WT/n;
    Avg_TAT = total_TAT/n;

    printf("\nID\tAT\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i+1, a[i].AT, temp[i], a[i].WT, a[i].TAT);
    }
    printf("\nAverage Waiting Time = %.2f", Avg_WT);
    printf("\nAverage Turnaround Time = %.2f\n", Avg_TAT);

    return 0;
}
