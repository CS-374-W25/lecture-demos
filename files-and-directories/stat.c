#include <sys/stat.h>
#include <stdio.h>

int main() {
	struct stat file_data;
	int result = stat("a.txt", &file_data);
	if (result == 0) {
		// Succeeded to stat the file
		printf("The size of a.txt is %d bytes\n", file_data.st_size);
	} else {
		// Failed to stat the file
	}
}
