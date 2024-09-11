
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include<sys/wait.h>

int main() {
    int pid_id, pid1_id;
    char childResultBuffer[100];

    pid_id = fork();


    if (pid_id < 0) {
        perror("Fork");
        return -1;
    }

    else if (pid_id == 0) {
        printf("Child Parent pid %d\n", pid_id);
        pid1_id = getpid();

        execl("/bin/ls", "-a");

        printf("Forked pid %d\n", pid1_id);
    }

    else {
        wait(NULL);
        printf("Parent pid: %d\n", pid_id);
        printf("Child pid1: %d\n", pid1_id);

        printf("Input buffer written by child: %s\n", childResultBuffer);
    }

    return 0;
}