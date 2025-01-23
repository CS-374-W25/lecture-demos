#include <stdio.h>

// main() is the entry point to your program.
// Also the exit point.
int main() {
	printf("Hello, World!\n");

	// int: Integer
	// float: Floating point number
	// double: Double-precision floating point number
	// char: Character ('A')
	// long int: Long integer (big numbers)
	
	// size_t: Size type (used to represent sizes of things)
	// ssize_t: Signed size type
	// off_t: Offset type
	double pi; // Declaring a variable
	// pi is "garbage", "uninitialized"
	
	// printf("%lf\n", pi); // Undefined behavior. pi has not been initialized

	pi = 3.14; // Initializing the variable (assigning the variable)

	// %d: Used to print int values
	// %f: Used to print float values
	// %lf: Used to print double values
	// %ld: Used to print longs (long ints)
	// %p: Used to print pointers
	// %s: Used to print C strings
	// %.2lf: Used to print doubles, specifically to 2 digits after decimal point
	printf("Hello %.2lf world!\n", pi);

	int x = 10; // Declares AND initializes

	double y = x + pi; // +, -, *, /, %

	x++; // Increments x by 1
	x += 1;
	x = x + 1;

	// NOT the same thing as:
	x + 1;

	

	return 0;
}
