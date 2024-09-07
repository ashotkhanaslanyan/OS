#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int ret1, ret2;
    pid_t fork1, fork2;

    fork1 = fork();
    if (fork1 < 0) {
        perror("fork");
    }
    else if (!fork1) {
        printf("Executing command ls\n");
        ret1 = execl("/bin/ls", "ls", NULL);
        if (ret1 < 0) {
            perror("execl");
        }
    }
    else if (fork1 > 0) {

        wait(NULL);
        fork2 = fork();
        if (fork2 < 0) {
            perror("fork");
        }
        else if (!fork2) {
            printf("Executing command date\n");
            ret2 = execl("/bin/date", "date", NULL);
            if (ret2 < 0) {
                perror("execl");
            }
        }
        else if (fork2 > 0) {
            wait(NULL);
            printf("Parent process done\n");
        }
    }

    return 0;
}