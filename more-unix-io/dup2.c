#include <unistd.h>
#include <fcntl.h>

int main() {
	pid_t fork_result = fork();
	if (fork_result == 0) {
		// Child process
		// echo hello, world > hello.txt
		// cat < data.txt
		int output_file = open("hello.txt", O_WRONLY | O_CREAT, 0666);
		dup2(output_file, STDOUT_FILENO);
		execlp("echo", "echo", "hello,", "world", (char*) NULL);
	} else {
		// Parent process
		int exit_status;
		waitpid(fork_result, &exit_status, 0);
	}
}
