#include "philo.h"

void	*die_or_eat(void *data)
{
	t_philo *ph;

	ph = (t_philo *)data;
	pthread_mutex_lock(ph->done);
}

void	exit_from_all(t_philo *ph)
{
	pthread_mutex_unlock(ph->done);
}

long	get_time()
{
	struct timeval cur;

	gettimeofday(&cur, NULL);
	return ((cur.tv_sec * 1000) + (cur.tv_usec) / 1000);
}


void	ft_usleep(long delay) /// delay in micro
{
	long	start;
	long	cur;
	long	newdelay;

	newdelay = delay - 10000;
	start = get_time() * 1000; /// in milisesconds * 1000 to convert to micro
	usleep(newdelay);
	while (1)
	{
		cur = get_time() * 1000;
		if (cur - start >= delay) /// here i compre them with the same unit micro
			return ;
	}
}
