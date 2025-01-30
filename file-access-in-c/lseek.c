#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int fd = open("alex.txt", O_RDONLY, 0);

	char ssn[10] = {0};

	// off_t
	// SEEK_CUR, SEEK_SET, SEEK_END
	lseek(fd, 16, SEEK_CUR);

	read(fd, ssn, 9 * sizeof(char));
	printf("%s\n", ssn);

	close(fd);
}
