#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

struct person {
	int age;
	double favorite_number; 
};

int main() {
	// "File descriptor"
	
	// mode_t: "mode type"
	
	// 0722
	// 111 010 010
	//
	// rwx -w- -w-

	mode_t old_umask = umask(0000);

	int fd = open("data.dat", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	// O_WRONLY == 1 == 00000001
	// O_CREAT == 2 ==  00000010
	//
	// O_WRONLY | O_CREAT == 00000011

	struct person p;
	p.age = 12;
	p.favorite_number = 12;

	ssize_t n_written = write(fd, &p, sizeof(struct person));

	close(fd);

	umask(old_umask);

	// chmod("hello.txt", 0722);
}
