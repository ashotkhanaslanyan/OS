#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int ret;
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
    }
    else if (!pid) {
        printf("Executing command grep\n");
        ret = execl("/bin/grep", "grep", "-n", "main", "Source/test.txt", (char *)NULL);
        if (ret < 0) {
            perror("execl");
        }
    }
    else if (pid > 0) {
        wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}