#include <stdio.h>

int main() {

    int intarr[5] = {1, 2, 3, 4, 5};
    int *ptrarr = intarr;

    for (int i = 0; i < 5; i++) {
        printf("Value at ptr + %d: %d\n", i, *(ptrarr + i));
        *(ptrarr + i) += 1;
    }

    printf("The resulting array directly: ");
    for (int i = 0; i < 5; i++) {
        printf("%d", intarr[i]);
    }
    printf("\nThe resulting array from pointer: ");
    for (int i = 0; i < 5; i++) {
        printf("%d", *(ptrarr + i));
    }
    printf("\n");

    return 0;
}