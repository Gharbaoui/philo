/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:55:17 by mel-ghar          #+#    #+#             */
/*   Updated: 2021/06/30 08:01:27 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*is_all_live(void	*data)
{
	t_philo	*ph;

	ph = (void *)data;
	while (1)
	{
		if (ph->state != 'E')
		{
			if (get_time() - ph->last_time_eat > ph->td)
			{
				pthread_mutex_lock(ph->print_lock);
				die_msg(ph);
				pthread_mutex_unlock(ph->done);
				break ;
			}
		}
		ph = ph->left;
		usleep(100);
	}
	return (NULL);
}

void	start_simulation(t_philo *ph)
{
	int			i;
	int			size;
	pthread_t	*thrs;

	init_vars(&thrs, &size, &i, ph);
	while (i < size)
	{
		ph->last_time_eat = *(ph->start_time);
		pthread_create(thrs + i, NULL, &life_cycle_of_ph, (void *)ph);
		ph = ph->left->left;
		i += 2;
	}
	wait_for_secon(&i, &ph);
	while (i < size)
	{
		ph->last_time_eat = *(ph->start_time);
		pthread_create(thrs + i, NULL, &life_cycle_of_ph, (void *)ph);
		ph = ph->left->left;
		i += 2;
	}
	pthread_create(&thrs[ph->total], NULL, &die_or_eat, ph);
	pthread_create(&thrs[ph->total + 1], NULL, &is_all_live, ph);
	pthread_join(thrs[ph->total], NULL);
	free(thrs);
}

void	wait_for_secon(int *i, t_philo **ph)
{
	int	size;

	usleep(1000);
	size = (*ph)->total;
	*i = 1;
	if (size % 2 == 0)
		*ph = (*ph)->left;
}

void	init_vars(pthread_t **thrs, int *size, int *i, t_philo *ph)
{
	*i = 0;
	*thrs = malloc(sizeof(pthread_t) * (ph->total + 2));
	*size = ph->total;
	(*ph->start_time) = get_time();
}

unsigned long long	get_time(void)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	return ((cur.tv_sec * 1000000) + cur.tv_usec);
}
