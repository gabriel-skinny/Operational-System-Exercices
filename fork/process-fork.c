#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    int x = 10;
    printf("X first value: %d\n", x);
    printf("X first adress: %x\n", &x);

    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    else if (pid == 0)
    {
        printf("X value on child: %d\n", x);
        printf("X child adress: %x\n", &x);
        x = 5;
        printf("X value modified on child: %d\n", x);
    }

    else
    {
        printf("X value on parent: %d\n", x);
        printf("X parent adress: %x\n", &x);
        x = 15;
        printf("X value modified on parent: %d\n", x);
    }

    return 0;
}