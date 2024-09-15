#include <stdio.h>
#include <stdlib.h>

void function1() {
    printf("Cleanup function1 called\n");
}

void function2() {
    printf("Cleanup function2 called\n");
}

int main() {

    atexit(function1);
    atexit(function2);

    printf("Call exit\n");

    exit(0);

    printf("After exit is called\n");

    return 0;
}