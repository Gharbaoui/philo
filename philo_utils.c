#include "philo.h"

int fill_info(t_info *ps, char **args, int argc)
{
    int i;

    i = 0;
    while  (++i < 6)
        if (is_number(args[i]) == 0)
            return (1);
    ps->number_of_ph = ft_atoi(args[1]);
    ps->forks_av = ps->number_of_ph;
    ps->td = ft_atoi(args[2]);
    ps->te = ft_atoi(args[3]);
    ps->ts = ft_atoi(args[4]);
    ps->philos = malloc(sizeof(t_philos));
    ps->philos->total = ps->number_of_ph;
    fill_philo(ps->philos);
    if (argc == 6)
        ps->num_of_meals = ft_atoi(args[5]);
    else
        ps->num_of_meals = 0;
    return (0);
}

int fill_philo(t_philos *ph)
{
    ph->phs = malloc(sizeof(t_ph) * ph->total);
}

void    print_info(t_info *ps)
{
    printf("Number of philos %d\n", ps->number_of_ph);
    printf("time to die %f\n", ps->td);
    printf("time to eat %f\n", ps->te);
    printf("time to sleep %f\n", ps->ts);
    printf("num of meals %d\n", ps->num_of_meals);
}
