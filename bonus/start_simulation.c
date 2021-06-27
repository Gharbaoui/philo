#include "philo.h"

int	start_simulation(t_info *info, int *pids)
{
    t_philo **philos;

    philos = get_philos(*info);
    start_philos(philos, pids, *info);
	return (0);
}

void    start_philos(t_philo **philos, int *pids, t_info info)
{
    int i;
    int num;

    num = info.num_of_phs / 2;
    i = -1;
    while (++i < num)
    {
        pids[i] = fork();
        if (pids[i] == 0)
            life_cycle_of_philo(philos[i]);
    }
    usleep(500);
    i = num - 1;
    num = info.num_of_phs;
    while (++i < num)
    {
        pids[i] = fork();
        if (pids[i] == 0)
            life_cycle_of_philo(philos[i]);
    }
}
