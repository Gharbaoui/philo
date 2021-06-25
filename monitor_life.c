#include "philo.h"

void	*is_all_live(void	*data)
{
	t_philo *ph;

	ph = (void *)data;
	while (1)
	{
		if (ph->state != 'E')
		{
			if (get_time() - ph->last_time_eat > (ph->td / 1000))
			{
				pthread_mutex_lock(ph->print_lock);
				die_msg(ph);
				exit_from_all(ph);
				break ;
			}
		}
		ph = ph->left;
		usleep(100);
	}
}

