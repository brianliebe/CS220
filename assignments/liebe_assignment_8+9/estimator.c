#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include "node.h"

/* must also code the averages into the program. */

extern estimator_max();
extern estimator_min();

#define NUM_NODES 10

int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}

void timeval_print(char *str, struct timeval *tv)
{
    printf("%s %ld sec, %06ld micro sec\n", str, tv->tv_sec, tv->tv_usec);
}

float calc_run() {
	struct timeval tvDiff, tvStart, tvEnd, max, min, final;
	
	gettimeofday(&tvStart, NULL);
	int max_value, min_value;
	max_value = min_value = 21000000; /* 20,000,000 */
	float num_NOPS = max_value * 100;  /* 2,000,000,000 */

	while (max_value > 0) {
		estimator_max();
		max_value--;
	}
	gettimeofday(&tvEnd, NULL);
	timeval_subtract(&max, &tvEnd, &tvStart);

	gettimeofday(&tvStart, NULL);
	while (min_value > 0) {
		estimator_min();
		min_value--;
	}
	gettimeofday(&tvEnd, NULL);
	timeval_subtract(&min, &tvEnd, &tvStart);

	timeval_subtract(&final, &max, &min);

	float time_difference = (final.tv_usec/1000000.0) + final.tv_sec;
	float final_time = num_NOPS * (1.0/time_difference);

	/*
	timeval_print("Max: \t\t", &max);
	timeval_print("Min: \t\t", &min);
	timeval_print("Difference: \t", &final);
	*/

	return final_time;
}


int main()
{
	float list[10];
	int i;
	for (i = 0; i < 10; i++) {
		list[i] = calc_run();
		/* printf("%.0f\n", list[i]); */
	}
	float final_value = list[0];
	for (i = 1; i < 10; i++) {
		final_value = (final_value + list[i])/2.0;
		/* printf("%.0f\n", final_value); */
	}

	printf("%.0f\n", final_value);
}









