NAME		= philo

GCC			= gcc -Wall -Wextra -Werror -lpthread

SRCS			=	mesag.c			\
					philo.c			\
					philo_thread.c	\
					print.c			\
					thread_exit.c	\
					monitor_life.c	\
					philo_utils.c	\
					small_libft.c	\

all : $(NAME)

$(NAME) : $(SRCS)
		$(GCC) $(SRCS) -o $(NAME)

clean :
		rm -f $(NAME)
fclean : clean

re: fclean all
