#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_philo
{
	int				*current_index;
	int				total;
	int				max_meals;
	int				id;
	float			td;
	float			ts;
	float			te;
	float			last_time_eat;
	int				meals;
	char			state;
	struct s_philo	*left;
	struct s_philo	*right;
	pthread_mutex_t	my_fork;
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
t_philo **all_philos(t_nums nums);
t_philo	*get_one_philo(t_nums nums, int	id);
t_philo	**free_all(t_philo **all, int index);
void	wire_philos(t_philo **all, int size);

////// thread  
int	start_simulation(t_philo *ph);
void	*life_cycle_of_ph(void *data);

////// print
void	print_sampl(t_philo *ph);
