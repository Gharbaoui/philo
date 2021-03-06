#include "philo.h"

void	*live_or_dead(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		if (ph->status != 'E')
		{
			if (get_time_sleep() - ph->last_time_eat > ph->td)
			{
				sem_wait(ph->s_print);
				die_msg(ph);
				sem_post(ph->s_died);
				break ;
			}
		}
		usleep(100);
	}
	return (NULL);
}

sem_t	*get_sem(char *name, int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT, 0777, value));
}
