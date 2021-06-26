/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:56:09 by mel-ghar          #+#    #+#             */
/*   Updated: 2021/06/26 11:56:10 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**free_all(t_philo **all, int index)
{
	while (--index >= 0)
		free(all[index]);
	free(all);
	return (NULL);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(long nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, str + i, 1);
}

int	non_number(char **nums, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (is_number(nums[i]) == 0)
			return (1);
	return (0);
}
