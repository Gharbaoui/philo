#include "philo.h"

void	fork_taken_msg(t_philo *ph)
{
	sem_wait(ph->s_print);
	ft_putnbr((get_time_sleep() - ph->start_time) / 1000);
	write(1, " ", 1);
	ft_putnbr(ph->id);
	write(1, " ", 1);
	ft_putstr("has taken a fork\n");
	sem_post(ph->s_print);
}

void	eating_msg(t_philo *ph)
{
	sem_wait(ph->s_print);
	ft_putnbr((get_time_sleep() - ph->start_time) / 1000);
	write (1, " ", 1);
	ft_putnbr(ph->id);
	write (1, " ", 1);
	ft_putstr("is eating\n");
	sem_post(ph->s_print);
}

void	sleeping_msg(t_philo *ph)
{
	sem_wait(ph->s_print);
	ft_putnbr((get_time_sleep() - ph->start_time) / 1000);
	write (1, " ", 1);
	ft_putnbr(ph->id);
	write (1, " ", 1);
	ft_putstr("is sleeping\n");
	sem_post(ph->s_print);
}

void	thinking_msg(t_philo *ph)
{
	sem_wait(ph->s_print);
	ft_putnbr((get_time_sleep() - ph->start_time) / 1000);
	write (1, " ", 1);
	ft_putnbr(ph->id);
	write (1, " ", 1);
	ft_putstr("is thinking\n");
	sem_post(ph->s_print);
}

void	die_msg(t_philo *ph)
{
	ft_putnbr((get_time_sleep() - ph->start_time) / 1000);
	write (1, " ", 1);
	ft_putnbr(ph->id);
	write (1, " died\n", 6);
}
