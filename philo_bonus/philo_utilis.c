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

t_philo	**get_philos(t_info info, sem_t *s_p, sem_t *forks, sem_t *s_died)
{
	int		i;
	int		size;
	t_philo	**philos;

	i = -1;
	size = info.num_of_phs;
	s_p = get_sem("sem_print", 1);
	forks = get_sem("sem_forks", info.num_of_phs);
	s_died = get_sem("sem_died", 1);
	sem_wait(s_died);
	philos = malloc(sizeof(t_philo *) * size);
	while (++i < size)
	{
		philos[i] = get_one_philo(info, i);
		philos[i]->s_print = s_p;
		philos[i]->s_forks = forks;
		philos[i]->s_died = s_died;
	}
	return (philos);
}

t_philo	*get_one_philo(t_info info, int id)
{
	t_philo	*ph;
	char	*name;

	ph = malloc(sizeof(t_philo));
	ph->id = id;
	ph->td = info.td * 1000;
	ph->te = info.te * 1000;
	ph->ts = info.ts * 1000;
	ph->status = 'T';
	ph->max_meals = info.meals;
	ph->meals = 0;
	name = ft_itoa(id);
	ph->s_done_eat = get_sem(name, 1);
	free(name);
	sem_wait(ph->s_done_eat);
	return (ph);
}

t_sem_info	*get_direct_access(t_philo **phs, t_info info, int *pids)
{
	int			i;
	t_sem_info	*tmp;

	i = -1;
	tmp = malloc(sizeof(t_sem_info));
	tmp->sem_eat = malloc(sizeof(sem_t *) * info.num_of_phs);
	while (++i < info.num_of_phs)
		tmp->sem_eat[i] = phs[i]->s_done_eat;
	tmp->s_d = phs[0]->s_died;
	tmp->pids = pids;
	tmp->s_print = phs[0]->s_print;
	tmp->size = info.num_of_phs;
	return (tmp);
}
