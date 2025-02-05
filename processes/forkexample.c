#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
	printf("Hello, World! Process %d starting\n", getpid());

	// In the parent, fork() returns the PID of the newly created child.
	// In the child process, fork() returns 0
	pid_t fork_result = fork();
	if (fork_result == 0) {
		// I am the child process
		printf("I am the child process!\n");

		// Execute the "echo" program
		//
		// argv[0]
		// execlp("ls", "ls", "/nfs/stak/users/guyera", (char*) NULL);
		char* args[3] = {
			"ls",
			"/nfs/stak/users/guyera",
			NULL
		};
		execvp("ls", args);
	} else {
		// I am the parent process
		printf("I am the parent process!\n");
	}
	printf("Goodbye, World! Process %d exiting\n", getpid());
}
