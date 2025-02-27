#include <stdio.h>
#include <pthread.h>

struct fizz_thread_args {
	pthread_mutex_t* mutex;
	pthread_cond_t* cv;
	int print_fizz = 0;
};

void* fizz(void* args) {
	
}

struct buzz_thread_args {
	pthread_mutex_t* mutex;
	pthread_cond_t* cv;
	int print_buzz = 0;
};

void* buzz(void* args) {
	
}

int main() {
	
}
