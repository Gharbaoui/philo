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

t_philo **get_philos(t_info info)
{
    int     i;
    int     size;
    sem_t   *s_p;
    sem_t   *forks;
    t_philo **philos;
    
    i = -1;
    size = info.num_of_phs;
    s_p = sem_open("sem_print", O_CREAT, 0777, 1);
    forks = sem_open("sem_forks", O_CREAT, 0777, info.num_of_phs);
    philos = malloc(sizeof(t_philo *) * size);
    while (++i < size)
    {
        philos[i] = get_one_philo(info, i);
        philos[i]->s_print = s_p;
        philos[i]->s_forks = forks;
    }
    return (philos);
}

t_philo *get_one_philo(t_info info, int id)
{
    t_philo *ph;

    ph = malloc(sizeof(t_philo));
    ph->id = id;
    ph->td = info.td * 1000;
    ph->te = info.te * 1000;
    ph->ts = info.ts * 1000;
    ph->status = 'T';
    ph->max_meals = info.meals;
    ph->meals = 0;
    ph->name_done_eat = ft_itoa(id);
    ph->s_done_eat = sem_open(ph->name_done_eat, O_CREAT, 0777, 1);
    sem_wait(ph->s_done_eat);
    return (ph);
}
