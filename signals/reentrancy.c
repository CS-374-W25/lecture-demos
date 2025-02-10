#include <stdio.h>


int a = 0;
int b = 1;
// This function is non-reentrant
void swap_globals() {
	int temp = a; // temp is 0
	a = b; // a to 0
	b = temp; // b to 0
}

void catch_sigtstp(int sig_number) {
	swap_globals();
}

int main() {
	struct sigaction sa = {0};
	sigfillset(&sa.sa_mask);
	sa.sa_handler = catch_sigtstp;
	sigaction(SIGTSTP, &sa, NULL);

	sigprocmask()
	swap_globals();
}
