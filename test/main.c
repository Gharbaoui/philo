#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
	struct timeval current_time;
	sleep(2);
	gettimeofday(&current_time, NULL);
	printf("seconds : %ld\nmicro seconds : %ld\n",
    current_time.tv_sec, current_time.tv_usec);
}
