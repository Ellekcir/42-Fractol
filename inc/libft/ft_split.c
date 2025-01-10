/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 01:27:03 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/12 21:58:47 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
s: The string to be split.
c: The delimiter character (used to separate and distinguish individual
pieces of data eg. '.' is a delimiter in destinguishing end and start of
a new sentence).

Allocates memory using malloc() and free(), it will return an array of
strings obtained by splitting 's' using the 'c' as a delimiter. The array
must end with a NULL pointer.

RESULT:
The array of new strings resulting from the split. NULL if the allocation
fails
*/

#include "libft.h"

static int	ft_charcount(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			counter++;
		i++;
	}
	return (counter);
}

static char	*ft_copysubstr(const char *s, int start, int fin)
{
	char	*ss;
	int		len;
	int		i;

	len = 0;
	while (start + len < fin)
		len++;
	ss = (char *)malloc(sizeof(char) * (len + 1));
	if (ss == NULL)
		return (NULL);
	i = 0;
	while (start < fin)
	{
		ss[i] = s[start];
		i++;
		start++;
	}
	ss[i] = '\0';
	return (ss);
}

static void	ft_freemem(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**ft_fillmemarray(char **array, const char *s, char c)
{
	int		start;
	size_t	len;
	size_t	i;

	start = -1;
	len = 0;
	i = 0;
	while (len <= ft_strlen(s))
	{
		if (s[len] != c && start < 0)
			start = len;
		else if ((s[len] == c || len == ft_strlen(s)) && start >= 0)
		{
			array[i++] = ft_copysubstr(s, start, len);
			if (array[i - 1] == NULL)
			{
				ft_freemem(array);
				return (NULL);
			}
			start = -1;
		}
		len++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (ft_charcount(s, c) + 1));
	if (array == NULL)
		return (NULL);
	array = ft_fillmemarray(array, s, c);
	return (array);
}
/*
#include <stdio.h>

int	main(void)
{
	char const	*s = "xxxHelloxPossumxxNumberx#1!";
	char		c = 'x';
	char		**result = ft_split(s, c);
	int			i = 0;
	
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
*/
