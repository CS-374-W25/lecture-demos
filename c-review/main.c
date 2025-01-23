#include <stdio.h>

int main() {
	int x = 2; // Automatic variable
	int y = 3; // Automatic variable
	printf("%lf\n", (double) x / y);

	// logical or: ||
	// logical NOT: !
	if (1 <= x && x <= 10) {
		printf("Eat more beef, kick less cats\n");
	} else if (y == 3) {
		// More code here
		char c;
	} else {
		// More code here
	}

	int i = 0;
	while (i < 10) {
		printf("Hello, World!\n");
		i++;
	}

	do {
		printf("Goodbye!\n");
	} while (0);

	// 1. Initialization statement
	// 2. Loop condition
	// 3. Post statement
	for (i = 0; i < 5; ++i) {
		printf("Deadbeef\n"); // Prints 5 times
	}

	// Arrays are homogeneous
	int n = 12;
	double my_favorite_numbers[n];
	my_favorite_numbers[0] = 3.14;

	// Aggregate initialization
	// 'w', 'o', 'r', 'd'
	char word[5] = {'w', 'o', 'r', 'd'};

	double my_array[100];

	
}
