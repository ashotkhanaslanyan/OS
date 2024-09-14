#include <stdio.h>

int main(){

    int var = 10;
    int *intptr = &var;

    printf("Address of var: %p \n", &var);
    printf("Value of intptr (Address of var): %p \n", intptr);

    *intptr += 10;

    printf("Value of var: %d \n", var);
    
    return 0;
}