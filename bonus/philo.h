#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct s_philo
{
	char	*done_eat_sem;
	char	*fork_name_sem;
}	t_philo;

typedef struct s_info
{
	int		num_of_phs;
	int		td;
	int		te;
	int		ts;
	int		meals;
}	t_info;

//// libft
long	help_ft_atoi(const char *str, int np);
long	ft_atoi(char *str);
int		is_digit(char c);
int		is_number(char *num);
int		non_number(char **nums, int size);
//// utilis
int		collect_data(int size, char **nums, t_info *info);
///// start simulation
int	start_simulation(t_info *info, int *pids);
