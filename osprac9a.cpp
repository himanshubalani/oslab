#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void recurse(int files[])
{
    int flag = 0, startBlock, len, j, k, ch;
    printf("\n\tFile Allocation Strategy - Sequential\n\n");
    printf("Enter the starting block and the length of the files\n");
    scanf("%d%d", &startBlock, &len);
    for (j = startBlock; j < (startBlock + len); j++)
    {
        if (files[j] == 0)
            flag++;
    }
    if (len == flag)
    {
        for (int k = startBlock; k < (startBlock + len); k++)
        {
            if (files[k] == 0)
            {
                files[k] = 1;
                printf("%d\t%d\n", k, files[k]);
            }
        }
        if (k != (startBlock + len - 1))
            printf("The file is allocated to the disk\n");
    }
    else
        printf("The file is not allocated to the disk\n");
    return;
}
int main()
{
    int files[50];
    for (int i = 0; i < 50; i++)
        files[i] = 0;
    printf("Files Allocated are :\n");
    recurse(files);
    printf("\nMade by Himanshu Balani");
    return 0;
}
