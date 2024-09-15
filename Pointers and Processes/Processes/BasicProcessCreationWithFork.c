#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
    }
    else if (!pid) {
        printf("Child process PID: %d\n", getpid());
    }
    else {
        printf("Parent process PID: %d\n", getpid());
    }

    return 0;
}