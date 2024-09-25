#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n;
    int sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));
    if (!arr) {
        perror("malloc");
        return -1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum of the array: %d\n", sum);
    free(arr);

    return 0;
}