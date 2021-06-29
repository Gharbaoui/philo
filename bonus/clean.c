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

void	check_if_hes_done(t_philo *ph)
{
	ph->meals++;
	if (ph->meals >= ph->max_meals)
	{
		sem_post(ph->s_done_eat);
	}
}

void	wait_for_all(int *pids, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		waitpid(pids[i], NULL, 0);
	kill (pids[i], SIGINT);
	waitpid(pids[i], NULL, 0);
}

void	free_philos(t_philo **philos, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(philos[i]);
	free(philos);
}

void	kill_all(int *pids, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		kill(pids[i], SIGTERM);
}
