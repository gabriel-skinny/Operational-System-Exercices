#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum;
void *summationThread(void *param);

int main(int argc, char *argv[])
{
    pthread_init
        pthread_t tid;
    pthread_attr_t attr;

    if (argc != 2)
    {
        fprintf(stderr, "Non argument passed\n");
        return -1;
    }
    if (atoi(argv[1]) < 0)
    {
        fprintf(stderr, "%d must be>= 0\n", atoi(argv[1]));
        return -1;
    }

    // Informa o tamanho da stack e informações de schedule usando os parametros default;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, summationThread, argv[1]);

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