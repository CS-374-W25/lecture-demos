#include <stdio.h>
#include <string.h>

int main() {
	// fopen()
	// fclose()
	// fprintf()
	// fgets() / getline() / fscanf()
	
	FILE* file = fopen("movies_sample_1.csv", "r");
	
	char* first_row = NULL;
	size_t n = 0;
	getline(&first_row, &n, file);
	first_row[strlen(first_row) - 1] = '\0';
	
	printf("%s\n", first_row);

	char* second_row = NULL;
	getline(&second_row, &n, file);

	feof(file)

	printf("%s\n", second_row);

	fclose(file);
}
