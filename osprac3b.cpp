//sjf
#include <stdio.h>
struct process
{
    int id, WT, AT, BT, TAT;
};
struct process a[10];
void swap(int *b, int *c)
{
    int tem;
    tem = *c;
    *c = *b;
    *b = tem;
}
int main()
{
    int n, check_ar = 0;
    int Cmp_time = 0;
    float Total_WT = 0, Total_TAT = 0, Avg_WT, Avg_TAT;
    printf("Enter the number of process \n");
    scanf("%d", &n);
    int ct[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter process %d arrival time\n", i + 1);
        scanf("%d", &a[i].AT);
        a[i].id = i + 1;
        if (i == 0)
            check_ar = a[i].AT;
        if (check_ar != a[i].AT)
            check_ar = 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter process %d burst time\n", i + 1);
        scanf("%d", &a[i].BT);
        a[i].id = i + 1;
        if (i == 0)
            check_ar = a[i].AT;
        if (check_ar != a[i].AT)
            check_ar = 1;
    }
    if (check_ar != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j].AT > a[j + 1].AT)
                {
                    swap(&a[j].id, &a[j + 1].id);
                    swap(&a[j].AT, &a[j + 1].AT);
                    swap(&a[j].BT, &a[j + 1].BT);
                }
            }
        }
    }
    if (check_ar != 0)
    {
        a[0].WT = a[0].AT;
        a[0].TAT = a[0].BT - a[0].AT;
        Cmp_time = a[0].TAT;
        Total_WT = Total_WT + a[0].WT;
        Total_TAT = Total_TAT + a[0].TAT;
        for (int i = 1; i < n; i++)
        {
            int min = a[i].BT;
            for (int j = i + 1; j < n; j++)
            {
                if (min > a[j].BT && a[j].AT <= Cmp_time)
                {
                    min = a[j].BT;
                    swap(&a[i].id, &a[j].id);
                    swap(&a[i].AT, &a[j].AT);
                    swap(&a[i].BT, &a[j].BT);
                }
            }
            a[i].WT = Cmp_time - a[i].AT;
            Total_WT = Total_WT + a[i].WT;
            Cmp_time = Cmp_time + a[i].BT;
            a[i].TAT = Cmp_time - a[i].AT;
            Total_TAT = Total_TAT + a[i].TAT;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int min = a[i].BT;
            for (int j = i + 1; j < n; j++)
            {
                if (min > a[j].BT && a[j].AT <= Cmp_time)
                {
                    min = a[j].BT;
                    swap(&a[i].id, &a[j].id);
                    swap(&a[i].AT, &a[j].AT);
                    swap(&a[i].BT, &a[j].BT);
                }
            }
            a[i].WT = Cmp_time - a[i].AT;
            Cmp_time = Cmp_time + a[i].BT;
            a[i].TAT = Cmp_time - a[i].AT;
            Total_WT = Total_WT + a[i].WT;
            Total_TAT = Total_TAT + a[i].TAT;
        }
    }
    Avg_WT = Total_WT / n;
    Avg_TAT = Total_TAT / n;
    printf("PROCESS  |\t Arrival|\tBurst|  Completion|  Turnaround|     Waiting|\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d       |   %10d | %10d | %10d | %10d | %10d |\n", i + 1, a[i].AT, a[i].BT,
               (a[i].AT + a[i].TAT), a[i].TAT, a[i].WT);
    }
    printf("\nAverge waiting time is:- %f\n", Avg_WT);
    printf("Average turnaround time is:- %f\n", Avg_TAT);
    printf("Made by Himanshu Balani");
    return 0;   }