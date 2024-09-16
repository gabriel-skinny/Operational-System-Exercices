#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
    pid_t pid;

    int fd;

    fd = open("./input.txt", O_RDONLY | O_WRONLY);

    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    else if (pid == 0)
    {
        printf("Child writing to fd: %d\n", fd);
        char message[6] = "testes";
        printf("Message: %s\n", message);
        write(fd, message, 6);
    }

    else
    {
        wait(NULL);
        char readingBuffer[6];
        int numberRead;
        printf("Parent reding from fd: %d\n", fd);
        numberRead = read(fd, readingBuffer, 6);
        printf("Number read: %d\n", numberRead);
        printf("Buffer read: %s\n", readingBuffer);
    }

    return 0;
}