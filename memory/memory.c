#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func()
{
    int x = 2;
    char *myStackString = "string";
    int y = 10;

    char *stringHeapPointer = (char *)malloc(strlen(myStackString) + 1);

    printf("Memory stack of X: %x\n", &x);
    printf("Memory Stack of string: %x\n", &myStackString);
    printf("Memory Stack of Y: %x\n", &y);

    strcpy(stringHeapPointer, myStackString);

    printf("Heap memory of string: %x\n", stringHeapPointer);
    printf("String on Heap: %s\n", stringHeapPointer);

    free(stringHeapPointer);

    printf("Heap memory of Y: %x\n", myStackString);
}

int main()
{
    printf("Code segment of func: %f\n", &func);

    func();

    return 0;
}