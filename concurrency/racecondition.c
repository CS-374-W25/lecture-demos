#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// In thread 1:
// 	lock mutex A
// 	lock mutex B
//	access / manipulate both shared resouces
//	unlock mutex B
//	unlock mutex A
//	
// In thread 2:
// 	lock mutex A
// 	lock mutex B
// 	access / manipulate the shared resources
// 	unlock mutex B
// 	unlock mutex A

struct worker_thread_arg {
	int thread_idx;
	double* sum;
	pthread_mutex_t* sum_mutex;
};

void* perform_work(void* arg) {
	struct worker_thread_arg* casted_arg = arg;

	int r = casted_arg->thread_idx;
	
	double spherical_volume = 4.0 / 3.0 * 3.141592 * r * r * r;
	
	pthread_mutex_lock(casted_arg->sum_mutex);
	// Critical section starts here
	double running_sum = *(casted_arg->sum);
	running_sum += spherical_volume;
	(*casted_arg->sum) = running_sum;
	// Critical section ends here
	pthread_mutex_unlock(casted_arg->sum_mutex);

	return NULL;
}

int main() {
	pthread_mutex_t sum_mutex;
	pthread_mutex_init(&sum_mutex, NULL);
	double sum = 0.0;
	pthread_t worker_threads[100];
	struct worker_thread_arg thread_args[100];

	int i;
	for (i = 0; i < 100; ++i) {
		thread_args[i].thread_idx = i;
		thread_args[i].sum = &sum;
		thread_args[i].sum_mutex = &sum_mutex;
		pthread_create(&worker_threads[i], NULL, perform_work, &thread_args[i]);
	}
	
	// The main thread will then continue to do its stuff here
	for (i = 0; i < 100; ++i) {
		pthread_join(worker_threads[i], NULL);
	}

	printf("The sum of sphere volumes is: %lf\n", sum);
}


// 
// mutex m;
// volatile sig_atomic_t global_variable;
// 
// sigint handler:
// 	lock mutex m
// 	fjdsafjdsa
// 	jfdsa
// 	fdsajfdsa
// 	unlock mutex m
//
// main():
// 	lock mutex m
// 	jfdsajfdsa
// 	fjdsafjdsa
// 	fdjsafjdsa
// 	unlock mutex m
//
// 
