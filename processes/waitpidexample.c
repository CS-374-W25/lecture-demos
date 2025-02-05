#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	printf("Parent process starting\n");
	pid_t fork_result = fork();

	if (fork_result == 0) {
		// The child
		execlp("echo", "echo", "Hello, World!", (char*) NULL);
		// This is dead code
		exit(1); // Something went very wrong!
	} else {
		// The parent
		int exit_status;
		printf("Parent process starts waiting\n");
		waitpid(fork_result, &exit_status, 0);
		printf("Parent process is done waiting\n");

		// wait(&exit_status);
		// equivalent to waitpid(-1, &exit_status, 0)

	}

	// waitpid()
}
