#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_ph
{
    int     id;
    char    status;
    int     counter;
}   t_ph;

typedef struct s_philos
{
    int     total;
    t_ph    *phs;
}   t_philos;

typedef struct s_info
{
    t_philos    *philos;
    int         number_of_ph;
    int         forks_av;
    float       td;
    float       te;
    float       ts;
    int         num_of_meals;
    
}   t_info;

long    help_ft_atoi(const char *str, int np);
long    ft_atoi(char *str);
int	is_number(char *num);
int	is_digit(char c);
int fill_info(t_info *ps, char **args, int argc);
int fill_philo(t_philos *ph);
void    print_info(t_info *ps);
