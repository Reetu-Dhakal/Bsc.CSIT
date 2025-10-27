#include<stdio.h>

struct process {
    int id, AT, BT, WT, TAT, PR;
};

struct process a[10];

void swap(int *b,int *c) {
    int temp=*c;
    *c=*b;
    *b=temp;
}

int main() {
    int n, Cmp_time=0;
    float Total_WT=0, Total_TAT=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Arrival Time, Burst Time and Priority:\n");
    for(int i=0;i<n;i++) {
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PR);
        a[i].id = i+1;
    }

    // Sort by Arrival Time first
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(a[j].AT > a[j+1].AT) {
                swap(&a[j].id,&a[j+1].id);
                swap(&a[j].AT,&a[j+1].AT);
                swap(&a[j].BT,&a[j+1].BT);
                swap(&a[j].PR,&a[j+1].PR);
            }
        }
    }

    // First process
    Cmp_time = a[0].AT + a[0].BT;
    a[0].TAT = Cmp_time - a[0].AT;
    a[0].WT  = a[0].TAT - a[0].BT;
    Total_TAT += a[0].TAT;
    Total_WT  += a[0].WT;

    // Remaining processes
    for(int i=1;i<n;i++) {
        int min = a[i].PR, pos = i;
        for(int j=i+1;j<n;j++) {
            if(a[j].AT <= Cmp_time && a[j].PR < min) {
                min = a[j].PR;
                pos = j;
            }
        }
        // Swap the chosen process into position i
        if(pos != i) {
            swap(&a[i].id,&a[pos].id);
            swap(&a[i].AT,&a[pos].AT);
            swap(&a[i].BT,&a[pos].BT);
            swap(&a[i].PR,&a[pos].PR);
        }

        a[i].WT = (Cmp_time > a[i].AT ? Cmp_time : a[i].AT) - a[i].AT;
        Cmp_time = (Cmp_time > a[i].AT ? Cmp_time : a[i].AT) + a[i].BT;
        a[i].TAT = Cmp_time - a[i].AT;

        Total_TAT += a[i].TAT;
        Total_WT  += a[i].WT;
    }

    printf("\nID\tAT\tBT\tPR\tWT\tTAT\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", a[i].id, a[i].AT, a[i].BT, a[i].PR, a[i].WT, a[i].TAT);
    }

    printf("\nAverage Waiting Time = %.2f\n", Total_WT/n);
    printf("Average Turnaround Time = %.2f\n", Total_TAT/n);

    return 0;
}
