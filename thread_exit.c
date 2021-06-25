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
