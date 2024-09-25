#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    
    arr = malloc(10 * sizeof(int));
    if (!arr) {
        perror("malloc");
        return -1;
    }
    
    printf("Enter 10 integers: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    arr = realloc(arr, 5 * sizeof(int));
    if(!arr) {
        perror("realloc");
        return -1;
    }

    printf("Array after resizing: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}