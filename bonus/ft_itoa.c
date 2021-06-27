#include "philo.h"

char	*ft_itoa(int value)
{
	char	*buffer;
	int		i;
	int		r;
	char	*tmp;

	i = 0;
	buffer = malloc(sizeof(char) * 4);
	while (value)
	{
		r = value % 10;
		if (r >= 10)
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;
		value /= 10;
	}
	if (i == 0)
		buffer[i++] = '0';
	buffer[i] = '\0';
	tmp = ft_reverse(buffer);
	free(buffer);
	return (tmp);
}

char	*ft_reverse(char *line)
{
	int		i;
	int		j;
	char	*tmp;

	j = ft_strlen(line);
	tmp = malloc(j + 1);
	i = -1;
	while (line[++i])
		tmp[i] = line[--j];
	tmp[i] = 0;
	return (tmp);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

