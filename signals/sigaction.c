#include <signal.h>
#include <unistd.h>

void catch_sigint(int signal_number) {
	// This is the function that I want to execute when the process
	// receives SIGINT
	write(STDOUT_FILENO, "Hello, World\n", 13);
}

int main() {
	struct sigaction sa_int = {0};
	// sa_int.sa_flags = 0;
	sigfillset(&sa_int.sa_mask);
	// sa_int.sa_handler = SIG_IGN; // "signal ignore"
	// sa_int.sa_handler = SIG_DFL; // "signal default"
	sa_int.sa_handler = catch_sigint;
	// sa_int.sa_sigaction = NULL
	
	// struct sigaction prev_action;
	sigaction(SIGINT, &sa_int, NULL);

	pause();
	pause();
	pause();
}
