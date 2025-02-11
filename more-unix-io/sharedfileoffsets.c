#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd = open("data.txt", O_WRONLY | O_CREAT, 0600);
	pid_t fork_result = fork();

	if (fork_result == 0) {
		// Child process
		write(fd, "The epic highs and lows of high school ", 39);
	} else {
		// Parent process
		int exit_status;
		waitpid(fork_result, &exit_status, 0);
		write(fd, "football\n", 9);
	}
}
