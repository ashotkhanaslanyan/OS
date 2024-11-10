#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 10

typedef struct {
    int *array;
    int start;
    int end;
} ThreadData;

void* sum_array(void* arg) {
    ThreadData *data = (ThreadData*) arg;
    int sum = 0;
    for (int i = data->start; i < data->end; i++) {
        sum += data->array[i];
    }
    printf("Sum of part from index %d to %d is: %d\n", data->start, data->end - 1, sum);
    return NULL;
}

int main() {
    int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pthread_t threads[2];
    ThreadData thread_data[2];

    thread_data[0].array = array;
    thread_data[0].start = 0;
    thread_data[0].end = ARRAY_SIZE / 2;

    thread_data[1].array = array;
    thread_data[1].start = ARRAY_SIZE / 2;
    thread_data[1].end = ARRAY_SIZE;

    for (int i = 0; i < 2; i++) {
        if (pthread_create(&threads[i], NULL, sum_array, &thread_data[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < 2; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            return 1;
        }
    }

    return 0;
}
