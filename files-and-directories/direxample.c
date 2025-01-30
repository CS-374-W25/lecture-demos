#include <dirent.h>
#include <stdio.h>

int main() {
	mkdir("hello", 0744);

	// ANSI color codes
	DIR* my_cool_directory = opendir("./");

	struct dirent* next_entry;
	while (next_entry = readdir(my_cool_directory)) {
		printf("%s\n", next_entry->d_name);
	}

	closedir(my_cool_directory);
}
