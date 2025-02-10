#include <signal.h>
#include <unistd.h>

int main() {
	sigset_t my_awesome_signals;
	sigfillset(&my_awesome_signals);
	setdelset(&my_awesome_signals, SIGINT);

	// my_awesome_signals contains everything but SIGINT
	
	sigemptyset(&my_awesome_signals);
	sigaddset(&my_awesomem_signals, SIGKILL);
	
	// my_awesome_signals contains SIGKILL
}
