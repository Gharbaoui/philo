#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo *start_philo;

	if (argc == 6 || argc == 5)
	{
		if (!init_philos(argc, argv, &start_philo))
			return (0);
		start_simulation(start_philo);
		sleep(10);
	}
}
