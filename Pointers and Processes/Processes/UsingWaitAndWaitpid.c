#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork1");
    }
    else if (!pid1) {
        printf("First child process PID: %d\n", getpid());
    }
    else {
        int status1;
        pid_t finished_pid1 = wait(&status1);
        printf("Parent process PID: %d\n", getpid());

        pid2 = fork();
        if (pid2 < 0) {
            perror("fork2");
        }
        else if (!pid2) {
            printf("Second child process PID: %d\n", getpid());
        }
        else {
            int status2;
            pid_t finished_pid2 = waitpid(pid2, &status2, 0);

            if (WIFEXITED(status2)) {
                printf("This message will print only after child process 2 is completed\n");
            }
            
            printf("Child 1 with PID: %d, exited with status: %d\n",
                finished_pid1, status1);
            printf("Child 2 with PID: %d, exited with status: %d\n",
                finished_pid2, status2);
        }
    }

    return 0;
}