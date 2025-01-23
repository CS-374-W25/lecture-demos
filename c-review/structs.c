#include <stdio.h>

struct person {
	int age;
	double favorite_number;
};

int main() {
	struct person joe;
	joe.age = 37;
	joe.favorite_number = 9.81;
	printf("Joe is %d years old\n", joe.age);

	struct person people[10];
}
