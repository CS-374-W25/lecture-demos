#include <stdio.h>

int main() {
	FILE* my_file = fopen("output.txt", "w");

	fprintf(my_file, "%d %.2lf\n", -12, 3.141592);

	fclose(my_file);
}
