#include <stdio.h>
#include <stdlib.h>

int main()
{

    int intArray[100];
    int *pointer = malloc(sizeof(int) * 100);

    printf("Stack memory int Array: %x\n", &intArray[0]);
    printf("Stack memory last int Array: %x\n", &intArray[100]);
    printf("Heap memory int pointer: %x\n", pointer);
    printf("Heap memory last int pointer: %x\n", &pointer[100]);
    intArray[100] = 2;
    pointer[2] = 4;

    free(pointer);

    return 0;
}