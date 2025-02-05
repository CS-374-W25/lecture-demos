int main() {
	char* my_string = "hello.csv";
	if (strlen(my_string) < 4) {
		// Handle this case
	}
	strcmp(my_string + strlen(my_string) - 4, ".csv");
}
