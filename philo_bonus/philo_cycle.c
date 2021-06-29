#include "philo.h"

void	life_cycle_of_philo(t_philo *philo)
{
	liveness_thread(philo);
	while (1)
	{
		if (philo->status == 'T')
			state_thinking(philo);
		else if (philo->status == 'E')
			state_eating(philo);
		else
			state_sleeping(philo);
	}
}

void	state_thinking(t_philo *ph)
{
	sem_wait(ph->s_forks);
	fork_taken_msg(ph);
	sem_wait(ph->s_forks);
	fork_taken_msg(ph);
	ph->status = 'E';
	ph->last_time_eat = get_time_sleep();
	eating_msg(ph);
	ft_usleep(ph->te);
	if (ph->max_meals > 0)
		check_if_hes_done(ph);
	sem_post(ph->s_forks);
	sem_post(ph->s_forks);
}

void	state_eating(t_philo *ph)
{
	ph->status = 'S';
	sleeping_msg(ph);
	ft_usleep(ph->ts);
}

void	state_sleeping(t_philo *ph)
{
	ph->status = 'T';
	thinking_msg(ph);
}

void	liveness_thread(t_philo *ph)
{
	pthread_t	live_mont;

	pthread_create(&live_mont, NULL, &live_or_dead, (void *)ph);
}
