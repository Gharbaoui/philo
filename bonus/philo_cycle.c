#include "philo.h"

void    life_cycle_of_philo(t_philo *philo)
{
    ///// working here
    philo->last_time_eat = get_time();
    philo->start_time = get_time();
    liveness_thread(philo);
    while (1)
    {
        if (philo->status == 'T')
            state_thinking(philo);
        else if (philo->status == 'E')
            state_eating(philo);
    }
}

void    state_thinking(t_philo *ph)
{
    long    stime;

    sem_wait(ph->s_forks);
    fork_taken_msg(ph);
    sem_wait(ph->s_forks);
    fork_taken_msg(ph);
    ph->status = 'E';
    stime = get_time();
    ph->last_time_eat = get_time();
    eating_msg(ph);
    ft_usleep(ph->te - ((get_time() - stime) * 1000));
    if (ph->max_meals > 0) //// maybe i will change it to >= 0 not > 0
        check_if_hes_done(ph);
    sem_post(ph->s_forks);
    sem_post(ph->s_forks);
}

void    check_if_hes_done(t_philo *ph)
{
    ph->meals++;
    if (ph->meals >= ph->max_meals)
    {
        sem_post(ph->s_done_eat);
    }
}

void    state_eating(t_philo *ph)
{

}

void    liveness_thread(t_philo *ph)
{
    
}
