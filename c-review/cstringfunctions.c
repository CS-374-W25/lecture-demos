#include <stdio.h>
#include <string.h>

int main() {
	const char* my_string = "Hello";
	size_t length = strlen(my_string);
	const char* my_string_2 = "Hello";

	printf("%d\n", length);

	if (strcmp(my_string, my_string_2) == 0) {
		printf("They're the same!\n");
	}

	// strcat
	char my_string_3[10];
	strcpy(my_string_3, my_string);

	// strtok
	char row[] = "Iron Man 3,2004";
	char* movie_title = strtok(row, ",");
	printf("%s\n", movie_title);
	char* movie_year = strtok(NULL, ",");

	printf("%s\n", row); // Iron Man 3
	
	// strtol(movie_year)
	// atoi()
	
	
	
}
