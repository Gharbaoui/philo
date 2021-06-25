#include "philo.h"

void	fork_taken_msg(long time, int id, pthread_mutex_t *plock)
{
	pthread_mutex_lock(plock);
	ft_putnbr(time);
	write(1, " ", 1);
	ft_putnbr((long)id);
	write(1, " ", 1);
	ft_putstr("has taken a fork\n");
	pthread_mutex_unlock(plock);
}

void	eating_msg(t_philo *ph)
{
	pthread_mutex_lock(ph->print_lock);
	ft_putnbr(get_time() - *ph->start_time);
	write (1, " ", 1);
	ft_putnbr(ph->id);
	write (1, " ", 1);
	ft_putstr("is eating\n");
	pthread_mutex_unlock(ph->print_lock);
}

void	sleeping_msg(t_philo *ph)
{
	pthread_mutex_lock(ph->print_lock);
	ft_putnbr(get_time() - *ph->start_time);
	write (1, " ", 1);
	ft_putnbr(ph->id);
	write (1, " ", 1);
	ft_putstr("is sleeping\n");
	pthread_mutex_unlock(ph->print_lock);
}

void	thinking_msg(t_philo *ph)
{
	pthread_mutex_lock(ph->print_lock);
	ft_putnbr(get_time() - *ph->start_time);
	write (1, " ", 1);
	ft_putnbr(ph->id);
	write (1, " ", 1);
	ft_putstr("is thinking\n");
	pthread_mutex_unlock(ph->print_lock);
}

void	die_msg(t_philo *ph)
{
	pthread_mutex_lock(ph->print_lock);
	ft_putnbr(get_time() - *ph->start_time);
	write (1, " ", 1);
	ft_putnbr(ph->id);
	write (1, " died\n", 5);
}
