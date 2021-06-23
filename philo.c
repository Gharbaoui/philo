#include "philo.h"

int main(int argc, char **argv)
{
    t_info  *ps;

    if (argc == 6)
    {
        ps = malloc(sizeof(t_info));
        if (!ps)
            return (1);
        if (fill_info(ps, argv, argc))
        {
            free(ps);
            return (1);
        }
        print_info(ps);
    }
}
