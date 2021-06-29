/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:23:24 by mel-ghar          #+#    #+#             */
/*   Updated: 2021/06/29 12:53:16 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <signal.h>

typedef struct s_philo
{
	int					id;
	unsigned long long	td;
	long				te;
	long				ts;
	unsigned long long	start_time;
	int					max_meals;
	int					meals;
	char				status;
	unsigned long long	last_time_eat;
	sem_t				*s_print;
	sem_t				*s_forks;
	sem_t				*s_done_eat;
	sem_t				*s_died;
}						t_philo;

typedef struct s_sem_info
{
	int		size;
	sem_t	**sem_eat;
	sem_t	*s_d;
	sem_t	*s_print;
	int		*pids;
}			t_sem_info;

typedef struct s_info
{
	int		num_of_phs;
	int		td;
	int		te;
	int		ts;
	int		meals;
}			t_info;

long				help_ft_atoi(const char *str, int np);
void				ft_putchar(char c);
void				ft_putnbr(long nb);
void				ft_putstr(char *str);
long				ft_atoi(char *str);
char				*ft_itoa(int value);
char				*ft_reverse(char *line);
int					is_digit(char c);
int					ft_strlen(char *str);
int					is_number(char *num);
int					non_number(char **nums, int size);
int					collect_data(int size, char **nums, t_info *info);
int					start_simulation(t_info *info, int *pids);
t_philo				**get_philos(t_info info, sem_t *s_p,
						sem_t *forks, sem_t *s_died);
t_philo				*get_one_philo(t_info info, int id);
void				start_philos(t_philo **philos, int *pids,
						t_info info, int num);
void				life_cycle_of_philo(t_philo *philo);
void				print_info(t_philo *ph);
long				get_time(void);
void				state_thinking(t_philo *ph);
void				state_eating(t_philo *ph);
void				state_sleeping(t_philo *ph);
void				liveness_thread(t_philo *ph);
void				*live_or_dead(void *philo);
void				fork_taken_msg(t_philo *ph);
void				eating_msg(t_philo *ph);
void				sleeping_msg(t_philo *ph);
void				thinking_msg(t_philo *ph);
void				*see_all(void *data);
void				die_msg(t_philo *ph);
void				ft_usleep(long delay);
void				check_if_hes_done(t_philo *ph);
void				check_all_proccess(t_philo **philos,
						int *pids, t_info info);
t_sem_info			*get_direct_access(t_philo **phs, t_info info, int *pids);
void				kill_all(int *pids, int size);
sem_t				*get_sem(char *name, int value);
unsigned long long	get_time_sleep(void);
void				set_time(t_philo **philos, int size);
void				*done_eating(void *data);
void				clean_sms(int size);
void				wait_for_all(int *pids, int size);
void				free_philos(t_philo **philos, int size);
#endif
