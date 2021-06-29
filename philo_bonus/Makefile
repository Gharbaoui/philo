NAME		= philo_bonus

GCC			= gcc -Wall -Wextra -Werror -lpthread

SRCS			=	clean.c				\
					messag.c			\
					philo_cycle.c		\
					small_libft.c		\
					ft_itoa.c			\
					philo.c				\
					philo_utilis.c		\
					start_simulation.c	\
					life_functions.c	\
					print.c				\
					time_functions.c	\


all : $(NAME)

$(NAME) : $(SRCS)
		$(GCC) $(SRCS) -o $(NAME)
clean :
		rm -f $(NAME) $(B_NAME)
fclean : clean

re: fclean all
