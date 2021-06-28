#include "philo.h"

unsigned long long	get_time_sleep(void)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	return ((cur.tv_sec * 1000000) + cur.tv_usec);
}


void	ft_usleep(long delay)
{
	long	start;
	long	cur;
	long	newdelay;

	newdelay = delay - 10000;
	start = get_time_sleep();
	usleep(newdelay);
	while (1)
	{
		cur = get_time_sleep();
		if (cur - start >= delay)
			return ;
	}
}

void	set_time(t_philo **philos, int size)
{
	int i;
	unsigned long long start_t;
	unsigned long long last_eat;

	i = -1;
	start_t = get_time_sleep();
	last_eat = get_time_sleep();
	while (++i < size)
	{
		philos[i]->start_time = start_t;
		philos[i]->last_time_eat = last_eat;
	}
}

