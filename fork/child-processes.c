
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int forked_pid_id, my_pid_id;
    char childResultBuffer[100];

    forked_pid_id = fork();
    fork();

    if (forked_pid_id < 0)
    {
        perror("Fork");
        return -1;
    }

    else if (forked_pid_id == 0)
    {
        printf("Child Parent pid %d\n", forked_pid_id);
        my_pid_id = getpid();
        printf("My child id: %d\n", my_pid_id);

        pipe
    }

    else
    {
        wait(NULL);
        my_pid_id = getpid();
        printf("Parent pid: %d\n", my_pid_id);
    }

    return 0;
}