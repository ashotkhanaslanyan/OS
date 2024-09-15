#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    
    pid_t pid1, pid2;
    int status;

    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork");
    }
    else if (!pid1) {
        printf("Child1 with PID: %d, exiting with code: 7\n", getpid());
        exit(7);
    }
    else {
        pid2 = fork();
        if (pid2 < 0) {
            perror("Fork");
        }
        else if (!pid2) {
            printf("Child2 with PID: %d, exiting with code: 9\n", getpid());
            exit(9);
        }
        else {
            int status1, status2;
            pid_t finished_pid1 = waitpid(pid1, &status1, 0);

            if (WIFEXITED(status1)) {
                printf("Child1 (PID: %d) exited normally with status: %d\n", finished_pid1, status1);
            }
            else {
                printf("Child1 exited abnormally\n");
            }

            pid_t finished_pid2 = waitpid(pid2, &status2, 0);

            if (WIFEXITED(status2)) {
                printf("Child2 (PID: %d) exited normally with status: %d\n", finished_pid2, status2);
            }
            else {
                printf("Child2 exited abnormally\n");
            }
        }
    }
}