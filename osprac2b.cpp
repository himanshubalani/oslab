#include <stdio.h>
#include <stdlib.h>
int main()
{
    int range, pre_head, curr_head;
    int a, b, c, x, y, z;
    int seek = 0, sub;
    printf("Enter the range of the queue:\n");
    scanf("%d", &range);
    int *que = (int *)calloc(range, sizeof(int));
    for (x = 0; x < range; x++)
    {
        printf("Enter %d element\n", x + 1);
        scanf("%d", &que[x]);
    }
    printf("Enter the previous head:\n");
    scanf("%d", &pre_head);
    printf("Enter the current head:\n");
    scanf("%d", &curr_head);
    for (a = 0; a < range; a++)
    {
        for (b = 0 + a; b < range; b++)
        {
            if (que[a] > que[b])
            {
                int temp;
                temp = que[a];
                que[a] = que[b];
                que[b] = temp;
            }
        }
    }
    printf("\n");
    if (curr_head > pre_head)
    {
        for (y = 0; y < range; y++)
        {
            if (curr_head < que[y])
            {
                sub = abs(curr_head - que[y]);
                seek += sub;
                break;
            }
        }
        int store = y;
        for (z = store; z < range; z++)
        {
            if (z == range - 1)
            {
                sub = (que[z] - que[y - 1]);
                seek += sub;
                break;
            }
            sub = abs(que[z] - que[z + 1]);
            seek += sub;
        }
        for (c = store - 1; c > 1; c--)
        {
            sub = abs(que[c] - que[c - 1]);
            seek += sub;
        }
        printf("\n\nThe total seek time is %d Disks\n", seek);
    }
    else if (curr_head < pre_head)
    {
        for (y = range - 1; y >= 0; y--)
        {
            if (curr_head > que[y])
            {
                sub = abs(curr_head - que[y]);
                seek += sub;
                break;
            }
        }
        int store = y;
        for (z = store; z >= 0; z--)
        {
            if (z == 0)
            {
                sub = (que[z] - que[y + 1]);
                seek += sub;
                break;
            }
            sub = abs(que[z] - que[z - 1]);
            seek += sub;
        }
        for (c = store + 1; c < (range - 2); c++)
        {
            sub = abs(que[c] - que[c + 1]);
            seek += sub;
        }
        printf("\n\nThe total seek time is %d Disks\n", seek);
    }
    free(que);
    printf("Made by Himanshu Balani");
    return 0;
}