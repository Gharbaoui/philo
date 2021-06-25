#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo
{
	long			*start_time;
	int				*phs_eaten;
	int				*current_index;
	int				total;
	int				max_meals;
	int				id;
	float			td;
	float			ts;
	float			te;
	long			last_time_eat;
	int				meals;
	char			state;
	struct s_philo	*left;
	struct s_philo	*right;
	pthread_mutex_t	fork;
	pthread_mutex_t	*lock_phs_eaten;
	pthread_mutex_t	*done;
	pthread_mutex_t	*print_lock;
}	t_philo;

typedef struct s_nums
{
	int		num_of_phs;
	float	td;
	float	te;
	float	ts;
	int		meals;
}	t_nums;

/* utilis    */
void	fill_nums(t_nums *nums, char **nums_str, int size);
int	init_philos(int argc, char **argv, t_philo **start);
int	non_number(char **nums, int size);
long    help_ft_atoi(const char *str, int np);
long    ft_atoi(char *str);
int	is_digit(char c);
int	is_number(char *num);
void	ft_putchar(char c);
void	ft_putnbr(long nb);
void	ft_putstr(char *str);
t_philo **all_philos(t_nums nums);
t_philo	*get_one_philo(t_nums nums, int	id);
t_philo	**free_all(t_philo **all, int index);
void	wire_philos(t_philo **all, int size);
void	link_all_to_done(t_philo **all, int size, pthread_mutex_t *done);
long	get_time();

////// thread  
int	start_simulation(t_philo *ph);
void	*life_cycle_of_ph(void *data);
void	*is_all_live(void	*data);
void	ft_usleep(long delay);

////// print
void	print_sampl(t_philo *ph);
void	print_all(t_philo *ph);
//// think
void	fork_taken_msg(long time, int id, pthread_mutex_t *plock);
void	eating_msg(t_philo *ph);
void	sleeping_msg(t_philo *ph);
void	thinking_msg(t_philo *ph);
void	die_msg(t_philo *ph);
void	state_thinking(t_philo *ph);
void	take_forks(t_philo *ph);
void	drop_forks(t_philo *ph);
void	check_num_meals(t_philo *ph);
void	exit_from_all(t_philo *ph);
void	*die_or_eat(void *data);

//// eat
void	state_eating(t_philo *ph);
void	state_sleeping(t_philo *ph);
