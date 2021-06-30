/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:55:10 by mel-ghar          #+#    #+#             */
/*   Updated: 2021/06/30 07:04:46 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_taken_msg(t_philo *ph)
{
	pthread_mutex_lock(ph->print_lock);
	ft_putnbr((get_time() - *(ph->start_time)) / 1000);
	write(1, " ", 1);
	ft_putnbr(ph->id);
	write(1, " ", 1);
	ft_putstr("has taken a fork\n");
	pthread_mutex_unlock(ph->print_lock);
}

void	eating_msg(t_philo *ph)
{
	pthread_mutex_lock(ph->print_lock);
	ft_putnbr((get_time() - *(ph->start_time)) / 1000);
	write (1, " ", 1);
	ft_putnbr(ph->id);
	write (1, " ", 1);
	ft_putstr("is eating\n");
	pthread_mutex_unlock(ph->print_lock);
}

void	sleeping_msg(t_philo *ph)
{
	pthread_mutex_lock(ph->print_lock);
	ft_putnbr((get_time() - *(ph->start_time)) / 1000);
	write (1, " ", 1);
	ft_putnbr(ph->id);
	write (1, " ", 1);
	ft_putstr("is sleeping\n");
	pthread_mutex_unlock(ph->print_lock);
}

void	thinking_msg(t_philo *ph)
{
	pthread_mutex_lock(ph->print_lock);
	ft_putnbr((get_time() - *(ph->start_time)) / 1000);
	write (1, " ", 1);
	ft_putnbr(ph->id);
	write (1, " ", 1);
	ft_putstr("is thinking\n");
	pthread_mutex_unlock(ph->print_lock);
}

void	die_msg(t_philo *ph)
{
	ft_putnbr((get_time() - *(ph->start_time)) / 1000);
	write (1, " ", 1);
	ft_putnbr(ph->id);
	write (1, " died\n", 6);
}
