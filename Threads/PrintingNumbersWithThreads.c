#include <stdio.h>
#include <pthread.h>

void* print_numbers(void* arg) {
    pthread_t tid = pthread_self();
    for (int i = 1; i <= 5; i++) {
        printf("Thread %lu: %d\n", (unsigned long)tid, i);
    }
    return NULL;
}

int main() {
    pthread_t threads[3];

    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, print_numbers, NULL) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            return 1;
        }
    }

    return 0;
}
