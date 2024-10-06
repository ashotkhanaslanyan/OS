#include <stdio.h>

int main() {

    int int_var;
    char char_var;
    double double_var;
    short short_var;

    printf("Size of int variable: %lu\n", sizeof(int_var));
    printf("Size of char variable: %lu\n", sizeof(char_var));
    printf("Size of double variable: %lu\n", sizeof(double_var));
    printf("Size of short variable: %lu\n", sizeof(short_var));

    printf("Address of int variable: %p\n", &int_var);
    printf("Address of char variable: %p\n", &char_var);
    printf("Address of double variable: %p\n", &double_var);
    printf("Address of short variable: %p\n", &short_var);

    return 0;
}