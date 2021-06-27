#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <wait.h>
#include <sys/time.h>

typedef struct s_philo
{
    int     id;
    int     td;
    int     te;
    int     ts;
    int     start_time;
    int     max_meals;
    int     meals;
    char    *name_done_eat;
    char    status;
    int     last_time_eat;
    sem_t   *s_print;
    sem_t   *s_forks;
    sem_t   *s_done_eat;
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
void	ft_putchar(char c);
void	ft_putnbr(long nb);
void	ft_putstr(char *str);
long	ft_atoi(char *str);
char	*ft_itoa(int value);
char	*ft_reverse(char *line);
int		is_digit(char c);
int     ft_strlen(char *str);
int		is_number(char *num);
int		non_number(char **nums, int size);
//// utilis
int		collect_data(int size, char **nums, t_info *info);
///// start simulation
int     start_simulation(t_info *info, int *pids);
t_philo **get_philos(t_info info);
t_philo *get_one_philo(t_info info, int id);
void    start_philos(t_philo **philos, int *pids, t_info info);
//// cycle
void    life_cycle_of_philo(t_philo *philo);
////// print
void    print_info(t_philo *ph);
void    wait_for_all(int *pids, int size);
long	get_time(void);
void    state_thinking(t_philo *ph);
void    state_eating(t_philo *ph);
void    liveness_thread(t_philo *ph);
/// messages
void	fork_taken_msg(t_philo *ph);
void	eating_msg(t_philo *ph);
void	sleeping_msg(t_philo *ph);
void	thinking_msg(t_philo *ph);
void	die_msg(t_philo *ph);
void	ft_usleep(long delay);
void    check_if_hes_done(t_philo *ph);
