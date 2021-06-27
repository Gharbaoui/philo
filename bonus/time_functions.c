#include "philo.h"

long	get_time(void)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	return ((cur.tv_sec * 1000) + (cur.tv_usec) / 1000);
}

void	ft_usleep(long delay)
{
	long	start;
	long	cur;
	long	newdelay;

	newdelay = delay - 10000;
	start = get_time() * 1000;
	usleep(newdelay);
	while (1)
	{
		cur = get_time() * 1000;
		if (cur - start >= delay)
			return ;
	}
}
