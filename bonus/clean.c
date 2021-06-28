#include "philo.h"

void	clean_sms(int size)
{
	char	*name;
	int		i;

	i = -1;
	while (++i < size)
	{
		name = ft_itoa(i);
		sem_unlink(name);
		free(name);
	}
	sem_unlink("sem_print");
	sem_unlink("sem_forks");
	sem_unlink("sem_died");
}
