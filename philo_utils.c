#include "philo.h"

int	init_philos(int argc, char **argv, t_philo **start)
{
	t_nums			nums;
	t_philo			**all;
	pthread_mutex_t	*done;

	done = malloc(sizeof(pthread_mutex_t));
	if (!done || non_number(argv, argc))
		return (0);
	fill_nums(&nums, argv, argc);
	all = all_philos(nums);
	pthread_mutex_init(done, NULL);
	pthread_mutex_lock(done);
	link_all_to_done(all, nums.num_of_phs, done);
	*start = *all;
	wire_philos(all, nums.num_of_phs);
	return (1);
}

void	link_all_to_done(t_philo **all, int size, pthread_mutex_t *done)
{
	int		i;
	int		*eaten;
	long	*start_time;
	pthread_mutex_t	*eat_lock;
	pthread_mutex_t	*print_lock;

	eat_lock = malloc(sizeof(pthread_mutex_t));
	print_lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(eat_lock, NULL);
	pthread_mutex_init(print_lock, NULL);
	eaten = malloc(sizeof(int));
	start_time = malloc(sizeof(long));
	*eaten = 0;
	i = -1;
	while (++i < size)
	{
		all[i]->done = done;
		all[i]->phs_eaten = eaten;
		all[i]->lock_phs_eaten = eat_lock;
		all[i]->print_lock = print_lock;
		all[i]->start_time = start_time;
	}
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
	p->td = nums.td * 1000;
	p->te = nums.te * 1000;
	p->ts = nums.ts * 1000;
	p->max_meals = nums.meals;
	p->total = nums.num_of_phs;
	p->state = 'T';
	pthread_mutex_init(&p->fork, NULL);
	return (p);
}

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
