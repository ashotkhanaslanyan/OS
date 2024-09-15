#include <stdio.h>

int main() {
    
    int num = 99;
    int *ptr = &num;
    int **ptr2 = &ptr;

    printf("Value of num: %d\n", num);
    printf("Value of num using ptr: %d\n", *ptr);
    printf("Value of num using ptr2: %d\n", **ptr2);

    return 0;
}