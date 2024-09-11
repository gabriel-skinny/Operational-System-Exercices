#define BUFFER_SIZE 30
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main() {
    printf("Running producer");
    int segment_id;
    char *shared_memory;

    printf("%s", "Before");
    segment_id = shmget(IPC_PRIVATE, BUFFER_SIZE, IPC_CREAT);
    if (segment_id == -1) {
        perror("shmget");
        return 1;
    }
    printf("%d", segment_id);

    shared_memory = (char *) shmat(segment_id, NULL, 0);
    if (shared_memory == (char *) - 1) {
        perror("shmat");
        return 1;
    }

    while(true) {    
        char inputBuffer[BUFFER_SIZE];

        printf("Write producer");

        scanf("%s", &inputBuffer);

        sprintf(shared_memory, inputBuffer);

        printf ("Shared memory: *%s \n" , shared_memory); 
    }

    return 0;
}