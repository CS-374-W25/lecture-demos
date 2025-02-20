#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	pid_t fork_result = fork();
	if (fork_result == 0) {
		// Child
		
		// Acquiring the lock
		int file_lock_fd;
		do {
			file_lock_fd = open("data.txt.lock", O_WRONLY | O_CREAT | O_EXCL, 0644);
		} while(file_lock_fd == -1);

		// Critical section starts here:
		FILE* data_file = fopen("data.txt", "a");
		fprintf(data_file, "I'm the child\n");
		fclose(data_file);
		// Ctirical section ends here
		
		// Releasing the lock
		close(file_lock_fd);
		remove("data.txt.lock");
	} else {
		// parent
		
		int file_lock_fd;
		do {
			file_lock_fd = open("data.txt.lock", O_WRONLY | O_CREAT | O_EXCL, 0644);
		} while(file_lock_fd == -1);

		// Critical section starts here:
		FILE* data_file = fopen("data.txt", "a");
		fprintf(data_file, "I'm the parent\n");
		fclose(data_file);
		// Ctirical section ends here

		close(file_lock_fd);
		remove("data.txt.lock");
	}
}
