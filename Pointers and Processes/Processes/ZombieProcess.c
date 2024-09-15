#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork");
    } else if (!pid) {
        printf("Child process (PID %d) is running\n", getpid());
        exit(0);
    } else {
        printf("Parent process (PID %d) created child process (PID %d)\n", getpid(), pid);
        sleep(20);
    }

    return 0;
}