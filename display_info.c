#include "philo.h"

void	print_sampl(t_philo *ph)
{
	printf("id: %d\n", ph->id);
}

void	print_all(t_philo *ph)
{
	printf("p lock %p\n", ph->print_lock);
	ph = ph->left;
	while (ph->id)
	{
		printf("p lock %p\n", ph->print_lock);
		ph = ph->left;
	}
}
