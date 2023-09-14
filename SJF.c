// Online C compiler to run C program online
#include <stdio.h>

int main() 
{
    int n;
    printf("Enter number of processes\n");
    scanf("%d",&n);
    int at[n+1],bt[n+1],sbt=0,sumt=0,sumw=0;
    for(int i=0;i<n;i++)
    {
        printf("Enter Arrival Time of Process P%d\n",i+1);
        scanf("%d",&at[i]);
        printf("Enter Burst Time of Process P%d\n",i+1);
        scanf("%d",&bt[i]);
        sbt+=bt[i];
    }
    bt[n] = 9999;
    for (int time = 0; time < sbt;) {
        int smallest = n;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && bt[i] > 0 && bt[i] < bt[smallest])
                smallest = i;
        }
        printf("P%d\t|\t%d\t|\t%d\n", smallest + 1, time + bt[smallest] - at[smallest], time - at[smallest]);
        sumt += time + bt[smallest] - at[smallest];
        sumw += time - at[smallest];
        time += bt[smallest];
        bt[smallest] = 0;
    }
    printf("\nAverage Waiting Time = %f", sumw * 1.0 / n);
    printf("\nAverage Turnaround Time = %f", sumt * 1.0 / n);
    return 0;
}
