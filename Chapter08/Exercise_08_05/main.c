#include <sys/wait.h>
#include <stdio.h>
#include <stdio.h>
#include <errno.h>
int main(void) {
	pid_t pid;
	if ((pid = fork()) < 0) {
		perror("fork error");
	} else if (pid == 0) {
		if (execlp("testinterp", "testinterp", "myarg1", "MY ARG2", (char *)0) < 0)
			perror("exec error");
	}
	if (waitpid(pid, NULL, 0) < 0)  /* parent */
		perror("waitpid error");
	exit(0);
}
