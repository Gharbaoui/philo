/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:55:25 by mel-ghar          #+#    #+#             */
/*   Updated: 2021/07/13 10:48:54 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*start_philo;

	if (argc == 6 || argc == 5)
	{
		if (!init_philos(argc, argv, &start_philo))
			return (0);
		start_simulation(start_philo);
		usleep(10000);
		clear_all(start_philo);
	}
}

void	clear_all(t_philo *ph)
{
	t_philo	*help;

	help = ph->left;
	ph->right->left = NULL;
	free_and_destroy(ph);
	while (help)
	{
		pthread_mutex_destroy(&ph->fork);
		free(ph);
		ph = help;
		help = ph->left;
	}
}

void	free_and_destroy(t_philo *ph)
{
	pthread_mutex_destroy(ph->print_lock);
	pthread_mutex_destroy(ph->done);
	pthread_mutex_destroy(ph->lock_phs_eaten);
	free(ph->print_lock);
	free(ph->done);
	free(ph->lock_phs_eaten);
}
