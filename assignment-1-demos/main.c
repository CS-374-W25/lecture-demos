#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
	char* name;
	int birth_year;
};

struct node {
	struct person value;
	struct node* next;
};

void skip_line(FILE* csv_file) {
	// Skip the first line (header) of the csv file
	char* dummy = NULL;
	size_t n = 0;
	getline(&dummy, &n, csv_file);
	free(dummy);
}

struct person person_from_line(FILE* csv_file) {
	char* row = NULL;
	size_t n = 0;
	ssize_t row_length = getline(&row, &n, csv_file);
	row[row_length - 1] = '\0';


	// Alexander Guyer\01999
	char* name = strtok(row, ",");
	char* birth_year = strtok(NULL, ",");

	// Convert representations
	
	int birth_year_int = strtol(birth_year, NULL, 10);

	struct person next_person;
	next_person.name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(next_person.name, name);
	next_person.birth_year = birth_year_int;

	// name: "Alexander Guyer"
	// birth_year: "1999"

	free(row);

	return next_person;
}

struct node* read_csv_file(FILE* csv_file) {
	skip_line(csv_file);
	
	struct node* head = NULL;
	
	int i = 0;
	while (i < 3) {
		struct person next_person = person_from_line(csv_file);
		// TODO add next_person into our linked list
		i++;
	}

	return NULL;
}

int main(int argc, char* argv[]) {
	// ./my_program ex.csv
	FILE* csv_file = fopen(argv[1], "r");

	struct node* head = read_csv_file(csv_file);

	fclose(csv_file);

	// present the menu to the user
}
