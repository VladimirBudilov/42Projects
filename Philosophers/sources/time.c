#include "../includes/philosophers.h"

long long int current_time(long long int start_time)
{
	struct timeval t1;
	gettimeofday(&t1, NULL);
	long long int milliseconds = (t1.tv_sec * 1000LL + t1.tv_usec / 1000) - start_time;
	return milliseconds;
}

long long int get_time(void)
{
	struct timeval t1;
	gettimeofday(&t1, NULL);
	long long int milliseconds = (t1.tv_sec * 1000LL + t1.tv_usec / 1000);
	return milliseconds;
}