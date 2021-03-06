#include "philo.h"

int	start_simulation(t_info *info, int *pids)
{
	t_philo	**philos;

	philos = get_philos(*info, NULL, NULL, NULL);
	start_philos(philos, pids, *info, 0);
	wait_for_all(pids, info->num_of_phs);
	free_philos(philos, info->num_of_phs);
	return (0);
}

void	start_philos(t_philo **philos, int *pids, t_info info, int num)
{
	int	i;

	num = info.num_of_phs / 2;
	i = -1;
	set_time(philos, info.num_of_phs);
	while (++i < num)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			life_cycle_of_philo(philos[i]);
	}
	i = num - 1;
	num = info.num_of_phs;
	while (++i < num)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			life_cycle_of_philo(philos[i]);
	}
	pids[i] = fork();
	if (pids[i] == 0)
	{
		check_all_proccess(philos, pids, info);
		return ;
	}
}

void	check_all_proccess(t_philo **philos, int *pids, t_info info)
{
	pthread_t	life_th;
	pthread_t	done_eat;
	t_sem_info	*sms;

	sms = get_direct_access(philos, info, pids);
	pthread_create(&life_th, NULL, &see_all, (void *)sms);
	pthread_create(&done_eat, NULL, &done_eating, (void *)sms);
	pthread_join(life_th, NULL);
	pthread_join(done_eat, NULL);
}

void	*see_all(void *data)
{
	t_sem_info	*sms;

	sms = (t_sem_info *)data;
	sem_wait(sms->s_d);
	clean_sms(sms->size);
	kill_all(sms->pids, sms->size);
	return (NULL);
}

void	*done_eating(void *data)
{
	t_sem_info	*sms;
	int			i;
	int			size;

	sms = (t_sem_info *)data;
	size = sms->size;
	i = -1;
	while (++i < size)
		sem_wait(sms->sem_eat[i]);
	sem_wait(sms->s_print);
	clean_sms(size);
	kill_all(sms->pids, sms->size);
	return (NULL);
}
