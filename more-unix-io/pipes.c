#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int pipe_fds[2];
	pipe(pipe_fds);

	pid_t fork_result = fork();
	if (fork_result == 0) {
		// First child process
		close(pipe_fds[1]);

		char message[49] = {'\0'};
		int total_bytes_read = 0;
		while (total_bytes_read < 48) {
			int n_bytes_read = read(
				pipe_fds[0],
				message + total_bytes_read,
				48 - total_bytes_read
			);
			total_bytes_read += n_bytes_read;
			if (n_bytes_read == 0) {
				// Error handle
			}
		}
		close(pipe_fds[0]);
		printf("My brother told me: %s\n", message);
	} else {
		// parent process
		pid_t fork_result_2 = fork();
		if (fork_result_2 == 0) {
			// Second child process
			close(pipe_fds[0]);
			char* message = "Hello, there brother! Have a good day at school!";
			int total_bytes_written = 0;
			int bytes_to_write = strlen(message);
			while (total_bytes_written < bytes_to_write) {
				int bytes_written = write(
					pipe_fds[1],
					message + total_bytes_written,
					bytes_to_write - total_bytes_written
				);
				total_bytes_written = bytes_written;
			}
			close(pipe_fds[1]);
		} else {
			close(pipe_fds[0]);
			close(pipe_fds[1]);
			int exit_status;
			waitpid(fork_result, &exit_status, 0);
			waitpid(fork_result_2, &exit_status, 0);
		}
	}
}
