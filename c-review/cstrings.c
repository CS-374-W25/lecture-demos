#include <stdio.h>
#include <stddef.h>

int main() {
	char my_string[20];
	my_string[0] = 'H';
	my_string[1] = 'e';
	my_string[2] = 'l';
	my_string[3] = 'l';
	my_string[4] = 'o';
	my_string[5] = '\0';

	printf("%s\n", my_string);

	char* string_a = "Hello";
	// string_a[0] = 'J'; // This is undefined behavior!

	const char* string_b = "Hello";
	// string_b[0] = 'J'; // This is a syntax error

	char string_c[20] = "Hello";
	string_c[0] = 'J';
	string_c[5] = 's';
	string_c[6] = '\0';
	printf("%s\n", string_c);

	char string_d[] = "Hello";
	// string_d[5] = 's';
	// printf("%s\n", string_d); // Buffer overread. Undefined behavior
	// string_d[6] = '\0'; // Buffer overflow. Undefined behavior
	
	printf("Enter your favorite sentence: ");
	//char favorite_sentence[201];
	//fgets(favorite_sentence, 201, stdin);
	char* favorite_sentence = NULL;
	size_t n = 0;
	getline(&favorite_sentence, &n, stdin);

	size_t length = strlen(favorite_sentence);
	favorite_sentence[length - 1] = '\0'; // Trim the \n, replace with \0
	

	printf("Really? Your favorite sentence is '%s'?!\n", favorite_sentence);

	printf("Enter your age: ");
	int user_age;
	scanf("%d", &user_age);

	printf("Really? Your age is '%d'?!\n", user_age);
}
