#include <stdio.h>

void print_number_to_two_decimal_places(double number) {
	printf("%.2lf\n", number);
}

char to_lower(char uppercase_letter) {
	return uppercase_letter + ('a' - 'A');
}

void change_me(int x[]) {
	x[0] = 100;
}



int main() {
	double y;

	print_number_to_two_decimal_places(3.141592);

	printf("%c\n", to_lower('S'));

	int x[10];
	x[0] = 13;
	change_me(x);
	printf("%d\n", x[0]);
}
