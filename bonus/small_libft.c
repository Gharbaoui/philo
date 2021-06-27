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

int	non_number(char **nums, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (is_number(nums[i]) == 0)
			return (1);
	return (0);
}
