#include "philo.h"

int	init_philos(int argc, char **argv, t_philo **start)
{
	t_nums nums;
	t_philo **all;

	if (non_number(argv, argc))
		return (0);
	fill_nums(&nums, argv, argc);
	all = all_philos(nums);
	*start = *all;
	wire_philos(all, nums.num_of_phs);
	return (1);
}

t_philo **all_philos(t_nums nums)
{
	t_philo	**all;
	int		i;

	i = -1;
	all = malloc(sizeof(t_philo *) * nums.num_of_phs);
	if (!all)
		return (NULL);
	while (++i < nums.num_of_phs)
	{
		all[i] = get_one_philo(nums, i);
		if (!all[i])
			return (free_all(all, i));
	}
	return (all);
}

void	wire_philos(t_philo **all, int size)
{
	int	left;
	int	right;
	int	i;

	i = -1;
	while (++i < size)
	{
		right = (i - 1 + size) % size;
		left = (i + 1 + size) % size;
		all[i]->left = all[left];
		all[i]->right = all[right];
	}

}

t_philo	*get_one_philo(t_nums nums, int	id)
{
	t_philo *p;

	p = malloc(sizeof(t_philo));
	if (!p)
		return (NULL);
	p->id = id;
	p->td = nums.td;
	p->te = nums.te;
	p->ts = nums.ts;
	p->max_meals = nums.meals;
	p->total = nums.num_of_phs;
	p->state = 'T';
	pthread_mutex_init(&p->my_fork, NULL);
	return (p);
}

t_philo	**free_all(t_philo **all, int index)
{
	while (--index >= 0)
		free(all[index]);
	free(all);
	return (NULL);
}
