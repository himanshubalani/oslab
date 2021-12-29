#include <stdio.h>
#include <stdlib.h>
int main()
{
    int range;
    printf("Enter the range of the quene\n");
    scanf("%d", &range);
    int queue[range];
    for (int ri = 0; ri < range; ri++)
    {
        printf("Enter %d element\n", ri + 1);
        scanf("%d", &queue[ri]);
    }
    int current_head;
    static int x, seek, store, sub;
    printf("Enter the current head\n");
    scanf("%d", &current_head);
    int y, z;
    for (y = 0; y < range; y++)
    {
        for (z = 1 + y; z < range; z++)
        {
            if (queue[y] > queue[z])
            {
                int temp;
                temp = queue[y];
                queue[y] = queue[z];
                queue[z] = temp;
            }
        }
    }
    int p;
    for (x = range - 1; x >= 0; x--)
    {
        if (current_head > queue[x])
        {
            sub = abs(current_head - queue[x]);
            store = x; //2
            seek += sub;
            break;
        }
    }
    for (p = store; p > 0; p--)
    {
        sub = abs(queue[p] - queue[p - 1]);
        seek += sub;
    }
    for (int p1 = store + 1; p1 < range - 1; p1++)
    {
        if (p1 == store + 1)
        {
            sub = abs(queue[p1] - queue[p]);
            seek += sub;
        }
        sub = abs(queue[p1] - queue[p1 + 1]);
        seek += sub;
    }
    printf("Total seek time is %d\n", seek);
    printf("Made by Himanshu Balani");
}