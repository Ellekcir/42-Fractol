#include "../inc/fractol.h"

int	ft_strncmp2(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0' && *s2 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void ft_putstr_fd2(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		ft_putstr_fd(s + 1, fd);
	}
}

// Make argument lowercase


void	to_lowercase(char *s)
{
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z')
		{
			*s = *s + ('a' - 'A');
		}
		s++;
	}
}
