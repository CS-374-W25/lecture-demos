#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	// strtol(), strtod()
	char* some_string = "1012";
	long int some_val = strtol(some_string, NULL, 10);
	printf("%ld\n", some_val);

	char* some_other_string = "3.141592";
	double some_other_val = strtod(some_other_string, NULL);
	printf("%lf\n", some_other_val);

	char* line = NULL;
	size_t n = 0;
	ssize_t c_string_length = getline(&line, &n, stdin);

	
	free(line);

	FILE* my_file = fopen(argv[1], "r");
	// free(my_file);
	fclose(my_file);
	
}
