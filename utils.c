#include <unistd.h>

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return(i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s || !*s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}


int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r')
		return (1);
	return (0);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
