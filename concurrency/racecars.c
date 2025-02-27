#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct worker_thread_arg {
	int thread_idx;
	int* race_started; // Pointer to bool (int) that says whether race has started
	pthread_mutex_t* race_started_mutex;
	pthread_cond_t* race_started_cv;
	int total_race_length; // e.g., in kilometers
	int speed; // Speed of this racecar in km / second
};

void* race(void* arg) {
	struct worker_thread_arg* casted_arg = arg;

	pthread_mutex_lock(casted_arg->race_started_mutex);
	while (*(casted_arg->race_started) == 0) {
		pthread_cond_wait(casted_arg->race_started_cv, casted_arg->race_started_mutex);
	}
	pthread_mutex_unlock(casted_arg->race_started_mutex);

	// At this point, we know that the race has started
	int total_distance_traveled = 0;
	while (total_distance_traveled < casted_arg->total_race_length) {
		sleep(1);
		total_distance_traveled += casted_arg->speed;
	}
	
	// At this point, the racecar has made it to the end of the race
	printf("Racecar %d has finished the race!\n", casted_arg->thread_idx);

	return NULL;
}

int main() {
	pthread_t worker_threads[5];
	struct worker_thread_arg thread_args[5];
	
	int race_started = 0;
	pthread_mutex_t race_started_mutex;
	pthread_mutex_init(&race_started_mutex, NULL);
	pthread_cond_t race_started_cv;
	pthread_cond_init(&race_started_cv, NULL);
	int speeds[5] = {100, 150, 200, 50, 250};

	int i;
	for (i = 0; i < 5; ++i) {
		thread_args[i].thread_idx = i;
		thread_args[i].race_started = &race_started;
		thread_args[i].race_started_mutex = &race_started_mutex;
		thread_args[i].total_race_length = 500;
		thread_args[i].speed = speeds[i];
		thread_args[i].race_started_cv = &race_started_cv;
		pthread_create(&worker_threads[i], NULL, race, &thread_args[i]);
	}
	
	pthread_mutex_lock(&race_started_mutex);
	race_started = 1;
	pthread_mutex_unlock(&race_started_mutex);
	pthread_cond_broadcast(&race_started_cv);

	for (i = 0; i < 5; ++i) {
		pthread_join(worker_threads[i], NULL);
	}
}
