#include "philo.h"

void    print_info(t_philo *ph)
{
    printf("semaphore eat done name: %s\n", ph->name_done_eat);
    printf("Id : %d\n", ph->id);
    printf("status %c\n", ph->status);
    printf("address print lock : %p\n", ph->s_print);
    printf("address forks lock: %p\n", ph->s_forks);
    printf("================================\n");
}
