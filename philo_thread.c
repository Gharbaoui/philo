#include "philo.h"

int	start_simulation(t_philo *ph)
{
	int			i;
	int			size;
	pthread_t	thrs[ph->total + 1];

	i = 0;
	size = ph->total;
	while (i < size)
	{
		pthread_create(thrs + i, NULL, &life_cycle_of_ph, (void *)ph);
		ph = ph->left->left;
		i += 2;
	}
	i = 1;
	ph = ph->left;
	while (i < size)
	{
		pthread_create(thrs + i, NULL, &life_cycle_of_ph, (void *)ph);
		ph = ph->left->left;
		i += 2;
	}
}

void	*life_cycle_of_ph(void *data)
{
	t_philo *ph;

	ph = (t_philo *)data;
	while (1)
	{
		if (ph->state == 'T')
		{
		}
		else if (ph->state == 'S')
		{
			
		}
		else
		{
			
		}
	}
}
