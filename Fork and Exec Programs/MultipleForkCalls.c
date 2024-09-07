#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	pid_t fork1, fork2, fork3;

	printf("Im Initial Parent! PID:%d\n", getpid());

	fork1 = fork();
	if (!fork1) {
		printf("I am the fork1! PID:%d\n", getpid());
	}
	else if (fork1 > 0) {
		printf("I'm the parent of fork1=%d, with PID:%d\n", fork1, getppid());
	}
	else if (fork1 < 0) {
		perror("fork");
	}

	fork2 = fork();
	if (!fork2) {
		printf("I am the fork2! PID:%d\n", getpid());
	}
	else if (fork2 > 0) {
		printf("I'm the parent of fork2=%d, with PID:%d\n", fork2, getppid());
	}
	else if (fork2 < 0) {
		perror("fork");
	}

	fork3 = fork();
	if (!fork3) {
		printf("I am the fork3! PID:%d\n", getpid());
	}
	else if (fork3 > 0) {
		printf("I'm the parent of fork3=%d, with PID:%d\n", fork3, getppid());
	}
	else if (fork3 < 0) {
		perror("fork");
	}

	printf("I'm the  Parent after 3 forks! PID:%d\n", getpid());

	return 0;
}
