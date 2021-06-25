#include "philo.h"

int	start_simulation(t_philo *ph)
{
	int			i;
	int			size;
	pthread_t	thrs[ph->total + 1];

	i = 0;
	size = ph->total;
	pthread_create(&thrs[ph->total], NULL, &die_or_eat, ph);
	(*ph->start_time) = get_time();
	while (i < size)
	{
		pthread_create(thrs + i, NULL, &life_cycle_of_ph, (void *)ph);
		ph = ph->left->left;
		i += 2;
	}
	i = 1;
	usleep(500);
	ph = ph->left;
	while (i < size)
	{
		pthread_create(thrs + i, NULL, &life_cycle_of_ph, (void *)ph);
		ph = ph->left->left;
		i += 2;
	}
	pthread_join(thrs[ph->total] , NULL);
}

void	*life_cycle_of_ph(void *data)
{
	t_philo *ph;

	ph = (t_philo *)data;
	while (1)
	{
		if (ph->state == 'T')
		{
			state_thinking(ph);
		}
		else if (ph->state == 'E')
		{
			state_eating(ph);
		}
		else
		{
			state_sleeping(ph);
		}
		if (get_time() - ph->last_time_eat > (ph->td / 1000))
		{
			die_msg(ph);
			pthread_mutex_unlock(ph->done);
		}
	}
}
////// thinking state
void	state_thinking(t_philo *ph)
{
	take_forks(ph);
	ph->state = 'E';
	eating_msg(ph);
	ft_usleep(ph->te);
	ph->last_time_eat = get_time(); //// in miliseconds
	if (ph->max_meals > 0)
		check_num_meals(ph);
	drop_forks(ph);
}

void	take_forks(t_philo *ph)
{
	pthread_mutex_lock(&ph->fork);
	fork_taken_msg(get_time() - *ph->start_time, ph->id, ph->print_lock);
	pthread_mutex_lock(&ph->left->fork);
	fork_taken_msg(get_time() - *ph->start_time, ph->id, ph->print_lock);
}

void	drop_forks(t_philo *ph)
{
	pthread_mutex_unlock(&ph->fork);
	pthread_mutex_unlock(&ph->left->fork);
}

void	check_num_meals(t_philo *ph)
{
	ph->meals++;
	if (ph->max_meals <= ph->meals)
	{
		pthread_mutex_lock(ph->lock_phs_eaten);
		*(ph->phs_eaten) = *(ph->phs_eaten) + 1;
		pthread_mutex_unlock(ph->lock_phs_eaten);
		if (*(ph->phs_eaten) > ph->total)
			exit_from_all(ph);
	}
}
/////////

///// eating state
void	state_eating(t_philo *ph)
{
	ph->state = 'S';
	///// display [sleeping]
	sleeping_msg(ph);
	ft_usleep(ph->ts);
}

void	state_sleeping(t_philo *ph)
{
	ph->state = 'T';
	///// display thinking
	thinking_msg(ph);
}
