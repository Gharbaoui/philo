NAME		= philo

GCC			= gcc -Wall -Wextra -Werror -lpthread

SRCS			=	src/mesag.c			\
					src/philo.c			\
					src/philo_thread.c	\
					src/print.c			\
					src/thread_exit.c	\
					src/monitor_life.c	\
					src/philo_utils.c	\
					src/small_libft.c	\


all : $(NAME)

$(NAME) : $(SRCS)
		$(GCC) $(SRCS) -o $(NAME)

clean :
		rm -f $(NAME)

fclean : clean

re: fclean all
