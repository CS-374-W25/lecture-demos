#include <stdio.h>
#include <pthread.h>

struct fizz_thread_args {
	pthread_mutex_t* mutex;
	pthread_cond_t* cv;
	int* print_fizz;
};

void* fizz(void* args) {
	struct fizz_thread_args* casted_arg = (struct fizz_thread_args*) args;

	while (1) {
		// Wait until told to print fizz
		pthread_mutex_lock(casted_arg->mutex);
		while (*(casted_arg->print_fizz) == 0) {
			// Wait and do nothing
			pthread_cond_wait(casted_arg->cv, casted_arg->mutex);
		}
		pthread_mutex_unlock(casted_arg->mutex);

		// Print fizz
		printf("fizz");

		pthread_mutex_lock(casted_arg->mutex);
		*(casted_arg->print_fizz) = 0;
		pthread_mutex_unlock(casted_arg->mutex);
		pthread_cond_signal(casted_arg->cv);
	}

	return NULL;
}

struct buzz_thread_args {
	pthread_mutex_t* mutex;
	pthread_cond_t* cv;
	int* print_buzz;
};

void* buzz(void* args) {
	struct buzz_thread_args* casted_arg = (struct buzz_thread_args*) args;

	while (1) {
		// Wait until told to print buzz
		pthread_mutex_lock(casted_arg->mutex);
		while (*(casted_arg->print_buzz) == 0) {
			// Wait and do nothing
			pthread_cond_wait(casted_arg->cv, casted_arg->mutex);
		}
		pthread_mutex_unlock(casted_arg->mutex);

		// Print buzz
		printf("buzz");

		pthread_mutex_lock(casted_arg->mutex);
		*(casted_arg->print_buzz) = 0;
		pthread_mutex_unlock(casted_arg->mutex);
		pthread_cond_signal(casted_arg->cv);
	}

	return NULL;
}

int main() {
	
	// On multiples of 3, we print fizz
	// On multiples of 5, we print buzz
	// On multiples of 15, we print fizzbuzz
	

	pthread_mutex_t fizz_mutex;
	pthread_mutex_init(&fizz_mutex, NULL);
	pthread_cond_t fizz_cv;
	pthread_cond_init(&fizz_cv, NULL);
	int print_fizz = 0;

	struct fizz_thread_args fizz_args;
	fizz_args.mutex = &fizz_mutex;
	fizz_args.cv = &fizz_cv;
	fizz_args.print_fizz = &print_fizz;

	pthread_t fizz_thread;
	pthread_create(&fizz_thread, NULL, fizz, &fizz_args);

	pthread_mutex_t buzz_mutex;
	pthread_mutex_init(&buzz_mutex, NULL);
	pthread_cond_t buzz_cv;
	pthread_cond_init(&buzz_cv, NULL);
	int print_buzz = 0;

	struct buzz_thread_args buzz_args;
	buzz_args.mutex = &buzz_mutex;
	buzz_args.cv = &buzz_cv;
	buzz_args.print_buzz = &print_buzz;

	pthread_t buzz_thread;
	pthread_create(&buzz_thread, NULL, buzz, &buzz_args);

	int counter;
	for (counter = 1; counter < 100; ++counter) {
		if (counter % 3 == 0) {
			// TODO Tell the fizz thread to print fizz
			pthread_mutex_lock(&fizz_mutex);
			print_fizz = 1;
			pthread_mutex_unlock(&fizz_mutex);
			pthread_cond_signal(&fizz_cv);

			// Waits until fizz has been printed
			pthread_mutex_lock(&fizz_mutex);
			while (print_fizz != 0) {
				pthread_cond_wait(&fizz_cv, &fizz_mutex);
			}
			pthread_mutex_unlock(&fizz_mutex);
		}

		if (counter % 5 == 0) {
			// TODO Tell the buzz thread to print buzz
			pthread_mutex_lock(&buzz_mutex);
			print_buzz = 1;
			pthread_mutex_unlock(&buzz_mutex);
			pthread_cond_signal(&buzz_cv);

			// Waits until buzz has been printed
			pthread_mutex_lock(&buzz_mutex);
			while (print_buzz != 0) {
				pthread_cond_wait(&buzz_cv, &buzz_mutex);
			}
			pthread_mutex_unlock(&buzz_mutex);
		}

		printf("\n");
	}
}
