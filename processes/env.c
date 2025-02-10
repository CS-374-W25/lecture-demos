#include <stdio.h>
#include <stdlib.h>

int main() {
	putenv("HELLO=hello");
	printf("The value of the HELLO environment variable is: %s\n", getenv("HELLO"));
}
