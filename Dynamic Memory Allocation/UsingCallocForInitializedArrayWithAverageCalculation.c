#include <stdio.h>
#include <stdlib.h>

int main() {
    void * calloc(size_t nr, size_t size);

    int *arr;
    int n;
    float sum = 0;

    printf("Input Length of Array: ");
    scanf("%d", &n);

    arr = calloc(n,sizeof(int));
    if(!arr) {
        perror("calloc");
        return -1;
    }

    printf("Array after calloc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    float avg = sum / n;
    printf("Average of the array: %.1f\n", avg);

    free(arr);

    return 0;

}