#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct worker_thread_arg {
	int thread_idx;
	double* sum;
};

void* perform_work(void* arg) {
	struct worker_thread_arg* casted_arg = arg;

	int r = casted_arg->thread_idx;
	(*casted_arg->sum) += 4.0 / 3.0 * 3.141592 * r * r * r;

	return NULL;
}

int main() {
	double sum = 0.0;
	pthread_t worker_threads[100];
	struct worker_thread_arg thread_args[100];

	int i;
	for (i = 0; i < 100; ++i) {
		thread_args[i].thread_idx = i;
		thread_args[i].sum = &sum;
		pthread_create(&worker_threads[i], NULL, perform_work, &thread_args[i]);
	}
	
	// The main thread will then continue to do its stuff here
	for (i = 0; i < 100; ++i) {
		pthread_join(worker_threads[i], NULL);
	}

	printf("The sum of sphere volumes is: %lf\n", sum);
}
