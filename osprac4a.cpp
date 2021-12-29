//Creation of child process
#include <stdio.h>
    int
    main()
{
    for (int i = 0; i < 5; i++) // loop will run n times (n=5)
    {
        if (fork() == 0)
        {
            printf("\n\t\t\Creation of Child Process");
            printf("\n\t\t\tProgram created by Albakhsh Sheikh ");
            printf("[son] pid %d from [parent] pid %d\n", getpid(), getppid());
            exit(0);
        }
    }
    for (int i = 0; i < 5; i++) // loop will run n times (n=5)
        wait(NULL);
}

//Zombie process
// A C program to demonstrate working of
// fork()/wait() and Zombie processes
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

    int
    main()
{

    int i;
    printf("\n\t\t\tCreation of Zombie process");
    printf("\n\t\t\tProgram created by Albakhsh Sheikh ");
    int pid = fork();
    if (pid == 0)
    {
        for (i = 0; i < 20; i++)
            printf("\nI am Child\n");
    }
    else
    {
        wait(NULL);
        printf("\nI am Parent\n");
        while (1)
            ;
    }
}

//Orphan process
#include <stdio.h>
#include <stdlib.h>
    int
    main()
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        printf("IAM CHILD PROCESS,MY PROCESS ID IS: %d", getpid());
        printf("\n THE CHILDS'S PARENT PROCESSS ID IS : %d\n", getppid());
        sleep(10);
        printf("\n *****AFTER 10 SECUNDS***");
        printf("\n IAM CHILD PROCESS,MY PROCESS ID IS: %d", getpid());
        printf("\n THE CHILDS'S PARENT PROCESS ID IS :%d\n", getppid());
    }
    else
    {
        printf("\nIAM PARENT PROCESS,MY PROCESS ID IS: %d", getpid());
        printf("\n THE PARENT'S PARENT PROCESS ID IS : %d\n", getppid());
    }
}
