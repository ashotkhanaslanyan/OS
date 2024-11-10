#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 5

typedef struct {
    int number;
} ThreadData;

void* calculate_square(void* arg) {
    ThreadData *data = (ThreadData*) arg;
    int square = data->number * data->number;
    printf("Square of %d is %d\n", data->number, square);
    return NULL;
}

int main() {
    int numbers[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    pthread_t threads[ARRAY_SIZE];
    ThreadData thread_data[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        thread_data[i].number = numbers[i];
        if (pthread_create(&threads[i], NULL, calculate_square, &thread_data[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            return 1;
        }
    }

    return 0;
}
