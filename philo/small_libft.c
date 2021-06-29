/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:56:17 by mel-ghar          #+#    #+#             */
/*   Updated: 2021/06/29 15:19:37 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	help_ft_atoi(const char *str, int np)
{
	long	result;
	long	max;

	result = 0;
	max = 9223372036854775807;
	while (is_digit(*str))
	{
		if (result <= (max - (*str - '0')) / 10)
			result = (result * 10) + *str - '0';
		else
		{
			if (np == -1)
				result = 0;
			else
				result = -1;
			break ;
		}
		str++;
	}
	return (result * np);
}

long	ft_atoi(char *str)
{
	int		np;

	np = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			np = -1;
		else
			np = 1;
	}
	return (help_ft_atoi(str, np));
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_number(char *num)
{
	if (*num == '-' || *num == '+')
		num++;
	while (*num)
	{
		if (!is_digit(*num))
			return (0);
		num++;
	}
	return (1);
}

int	fill_nums(t_nums *nums, char **nums_str, int size)
{
	nums->num_of_phs = ft_atoi(nums_str[1]);
	nums->td = ft_atoi(nums_str[2]);
	nums->te = ft_atoi(nums_str[3]);
	nums->ts = ft_atoi(nums_str[4]);
	nums->meals = -1;
	if (size == 6)
	{
		nums->meals = ft_atoi(nums_str[5]);
		if (nums->meals <= 0)
			return (1);
	}
	if (nums->num_of_phs <= 0 || nums->td < 60 || nums->te < 60
		|| nums->ts < 60 || nums->num_of_phs > 200)
		return (1);
	return (0);
}
