#include <stdio.h>
// ./a.out hello world

int main(int argc, const char* argv[]) {
	int i;
	for (i = 0; i < argc; ++i) {
		printf("%s\n", argv[i]);
	}
}
