#include <stdio.h>
#include <stddef.h>

struct person {
	int age;
	double favorite_number;
};

void change_me(int* x) {
	*x = 100;
}

double* create_5() {
	double five = 5.0;
	return &five;
}

int main() {
	int x = 13;
	change_me(&x);
	// printf("%d\n", x);

	double* my_pointer = create_5(); // Dangling pointer
	// printf("%lf\n", *my_pointer); // Undefined behavior. use-after-free

	double* p = NULL; // NULL is equivalent to 0x00000000

	if (p) {
		// printf("P points to the value %lf\n", *p);
	} else {
		// printf("P doesn't point to anything!\n");
	}

	char my_array[20];

	// char* beginning_of_array = &(my_array[0]);
	// char* beginning_of_array = &my_array;
	char* beginning_of_array = my_array;

	beginning_of_array[0] = 'H';
	beginning_of_array[1] = 'e';
	beginning_of_array[2] = 'l';
	beginning_of_array[3] = 'l';
	beginning_of_array[4] = 'o';

	struct person jennifer;
	jennifer.age = 37;
	struct person* jennifer_pointer = &jennifer;

	(*jennifer_pointer).age = 20; // This is the same thing
	jennifer_pointer->age = 20; // This is the same thing
}
