/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:56:25 by mel-ghar          #+#    #+#             */
/*   Updated: 2021/06/26 14:14:22 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*die_or_eat(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	pthread_mutex_lock(ph->done);
	return (NULL);
}

void	exit_from_all(t_philo *ph)
{
	pthread_mutex_lock(ph->print_lock);
	pthread_mutex_unlock(ph->done);
}

void	ft_usleep(long delay)
{
	long	start;
	long	cur;
	long	newdelay;

	newdelay = delay - 10000;
	start = get_time() * 1000;
	usleep(newdelay);
	while (1)
	{
		cur = get_time() * 1000;
		if (cur - start >= delay)
			return ;
	}
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
