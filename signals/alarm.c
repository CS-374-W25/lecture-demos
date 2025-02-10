#include <signal.h>
#include <unistd.h>

int main() {
	alarm(10);
	pause();
}
