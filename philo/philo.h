/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 10:59:10 by mel-ghar          #+#    #+#             */
/*   Updated: 2021/06/29 15:29:49 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	unsigned long long	*start_time;
	int					*phs_eaten;
	int					total;
	int					max_meals;
	int					id;
	unsigned long long	td;
	float				ts;
	float				te;
	unsigned long long	last_time_eat;
	int					meals;
	char				state;
	struct s_philo		*left;
	struct s_philo		*right;
	pthread_mutex_t		fork;
	pthread_mutex_t		*lock_phs_eaten;
	pthread_mutex_t		*done;
	pthread_mutex_t		*print_lock;
}	t_philo;

typedef struct s_nums
{
	int		num_of_phs;
	float	td;
	float	te;
	float	ts;
	int		meals;
}	t_nums;

int					fill_nums(t_nums *nums, char **nums_str, int size);
int					init_philos(int argc, char **argv, t_philo **start);
int					non_number(char **nums, int size);
long				help_ft_atoi(const char *str, int np);
long				ft_atoi(char *str);
int					is_digit(char c);
int					is_number(char *num);
void				ft_putchar(char c);
void				ft_putnbr(long nb);
void				ft_putstr(char *str);
t_philo				**all_philos(t_nums nums);
t_philo				*get_one_philo(t_nums nums, int	id);
t_philo				**free_all(t_philo **all, int index);
void				wire_philos(t_philo **all, int size);
void				link_all_to_done(t_philo **all, int size,
						pthread_mutex_t *done);
long				get_time(void);
unsigned long long	get_time_sleep(void);
void				start_simulation(t_philo *ph);
void				wait_for_secon(int *i, t_philo **ph);
void				init_vars(pthread_t **thrs, int *size, int *i, t_philo *ph);
void				*life_cycle_of_ph(void *data);
void				*is_all_live(void	*data);
void				ft_usleep(long delay);
void				fork_taken_msg(unsigned long long time,
						int id, pthread_mutex_t *plock);
void				eating_msg(t_philo *ph);
void				sleeping_msg(t_philo *ph);
void				thinking_msg(t_philo *ph);
void				die_msg(t_philo *ph);
void				state_thinking(t_philo *ph);
void				take_forks(t_philo *ph);
void				drop_forks(t_philo *ph);
void				check_num_meals(t_philo *ph);
void				exit_from_all(t_philo *ph);
void				*die_or_eat(void *data);
void				state_eating(t_philo *ph);
void				state_sleeping(t_philo *ph);
void				clear_all(t_philo *ph);
void				free_and_destroy(t_philo *ph);
#endif
