#include "philo.h"

int	collect_data(int size, char **nums, t_info *info)
{
	if (non_number(nums, size))
		return (1);
	info->num_of_phs = ft_atoi(nums[1]);
	info->td = ft_atoi(nums[2]);
	info->te = ft_atoi(nums[3]);
	info->ts = ft_atoi(nums[4]);
	info->meals = -1;
	if (size == 6)
	{
		info->meals = ft_atoi(nums[5]);
		if (info->meals < 0)
			return (1);
	}
	if (info->num_of_phs <= 0 || info->num_of_phs > 200 || info->td < 60
		|| info->ts < 60 || info->te < 60)
		return (1);
	return (0);
}
