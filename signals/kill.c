#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t fork_result = fork();
	if (fork_result == 0) {
		// We are the child
		sleep(1000);
	} else {
		// We are the parent
		sleep(5);
		kill(fork_result, SIGINT);
		int exit_status;
		int wait_result = waitpid(fork_result, &exit_status, WNOHANG);
		if (wait_result) {
			printf("The child process has terminated\n");
		}
	}
}
