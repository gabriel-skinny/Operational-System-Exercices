#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 10;
void *summationThread(void *param);

int main(int argc, char *argv[])
{

    pthread_t tid;
    pthread_attr_t attr;
    int scope;

    // Informa o tamanho da stack e informações de schedule usando os parametros default;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, summationThread, argv[1]);

    phtread_attr

        printf("Thread created %d on main thread\n", tid);
    pthread_join(tid, NULL);

    printf("sum = %d\n", sum);
}

void *summationThread(void *param)
{
    printf("Thread started\n");
    int i, upper = atoi(param);
    sum = 0;

    for (i = 1; i <= upper; i++)
    {
        sum += i;
    }

    pthread_exit(0);
}