#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	printf("Parent process starting\n");
	pid_t fork_result = fork();

	if (fork_result == 0) {
		// The child
		execlp("ls", "ls", "fdsjafjdsajfdsa", (char*) NULL);
		// This is dead code
	} else {
		// The parent
		int exit_status;
		pid_t wait_result;
		do {
			wait_result = waitpid(fork_result, &exit_status, WNOHANG);
			if (wait_result == 0) {
				printf("The child process has not yet terminated!\n");
			}
		} while (wait_result == 0);

		if (WIFEXITED(exit_status)) {
			int exit_code = WEXITSTATUS(exit_status);
			printf("The child exited normally with code %d\n", exit_code);
		} else if (WIFSIGNALED(exit_status)) {
			int signal_number = WTERMSIG(exit_status);
			printf("The child was killed by signal number %d\n", signal_number);
		}

		printf("The child process has terminated!\n");
	}

	// waitpid()
}
