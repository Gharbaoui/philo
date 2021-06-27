#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	int		*pids;

	if (argc == 6 || argc == 5)
	{
		info = malloc(sizeof(t_info));
		if (collect_data(argc, argv, info))
		{
			free(info);
			return (1);
		}
		pids = malloc(sizeof(int) * (info->num_of_phs + 1));
		if (!pids)
		{
			free(info);
			return (1);
		}
		start_simulation(info, pids);
        wait_for_all(pids, info->num_of_phs);
	}
}

void    wait_for_all(int *pids, int size)
{
    int i;

    i = -1;
    while (++i < size)
        wait(NULL);
}
