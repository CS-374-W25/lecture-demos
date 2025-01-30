#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct person {
	int age;
	double favorite_number; 
};

int main() {
	int fd = open("data.dat", O_RDONLY, 0);

	struct person p;

	ssize_t n_read = read(fd, &p, sizeof(struct person));

	close(fd);

	printf("The person is %d years old, and their fav number is %.2lf\n", p.age, p.favorite_number);
}
