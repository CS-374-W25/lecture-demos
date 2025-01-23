#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	// Equivalent to new
	double* array = (double*) malloc(sizeof(double) * n);

	array = realloc(array, sizeof(double) * (n + 1));

	// Equivalent to delete
	free(array);
}
