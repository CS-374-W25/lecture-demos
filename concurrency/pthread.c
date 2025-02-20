#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct worker_thread_arg {
	int thread_idx;
	char* message;
};

void* perform_work(void* arg) {
	struct worker_thread_arg* casted_arg = arg;
	printf(
		"I'm thread with index %d. The main thread sent this message to me: %s\n",
		casted_arg->thread_idx,
		casted_arg->message
	);

	float* the_result = (float*) malloc(sizeof(float));
	*the_result = 3.141592;
	return the_result;
}

int main() {
	pthread_t secondary_thread;
	char* message = "Have a good day at work!";
	struct worker_thread_arg thread_arg = {0, message};
	pthread_create(&secondary_thread, NULL, perform_work, &thread_arg);
	
	// The main thread will then continue to do its stuff here
	void* thread_return_value;
	pthread_join(secondary_thread, &thread_return_value);
	
	float* casted_return_value = thread_return_value;
	printf("The worker thread computed the value: %f\n", *casted_return_value);
}
