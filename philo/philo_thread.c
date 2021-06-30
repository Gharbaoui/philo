/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:55:35 by mel-ghar          #+#    #+#             */
/*   Updated: 2021/06/30 07:23:57 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_cycle_of_ph(void *data)
{
	t_philo	*ph;

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
	}
}

void	state_thinking(t_philo *ph)
{
	take_forks(ph);
	ph->state = 'E';
	eating_msg(ph);
	ph->last_time_eat = get_time();
	ft_usleep(ph->te);
	if (ph->max_meals > 0)
		check_num_meals(ph);
	drop_forks(ph);
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

void	state_eating(t_philo *ph)
{
	ph->state = 'S';
	sleeping_msg(ph);
	ft_usleep(ph->ts);
}

void	state_sleeping(t_philo *ph)
{
	ph->state = 'T';
	thinking_msg(ph);
}
