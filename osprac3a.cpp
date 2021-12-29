//FCFS
#include <stdio.h>
int main()
{
    int pro;
    printf("Enter number of processes\n");
    scanf("%10d", &pro); //5
    int arr[pro], bur[pro];
    int comp[pro], tur[pro], wait[pro];
    int i;
    for (i = 0; i < pro; i++)
    {
        printf("Enter process %d arrival time\n", i + 1);
        scanf("%10d", &arr[i]);
    }
    for (i = 0; i < pro; i++)
    {
        printf("Enter process %d burst time\n", i + 1);
        scanf("%10d", &bur[i]);
    }
    for (i = 0; i < pro; i++)
    {
        if (i == 0)
        {
            comp[i] = 0 + bur[i];
            continue;
        }
        comp[i] = comp[i - 1] + bur[i];
    }
    for (i = 0; i < pro; i++)
    {
        tur[i] = comp[i] - arr[i];
        wait[i] = tur[i] - bur[i];
    }
    float avgtur = 0, avgwait = 0;
    for (i = 0; i < pro; i++)
    {
        avgtur = avgtur + (float)tur[i];
        avgwait = avgwait + (float)wait[i];
    }
    printf("PROCESSES|\t Arrival|\tBurst|  Completion|  Turnaround|     Waiting|\n");
    for (i = 0; i < pro; i++)
    {
printf("P%d       |   %10d | %10d | %10d | %10d | %10d |\n",i+1,arr[i],bur[i],comp[i],tur[i],wait[i]);
    }
    printf("\nAverage turnaround time is %f\n", avgtur / pro);
    printf("Average Waiting time is %f\n", avgwait / pro);
    printf("Made by Himanshu Balani");
    return 0;
}