/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:21:39 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 00:32:06 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
     The strchr() function locates the first occurrence of c (converted to
     a char) in the string pointed to by s.  The terminating null character
     is considered to be part of the string; therefore if c is `\0', the
     functions locate the terminating `\0'.
RETURN:
     The functions strchr() and strrchr() return a pointer to the located
     character, or NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	chr;
	int		i;

	chr = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != chr)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (&str[i]);
}
/*
#include <stdio.h>

int	main()
{
	char	s[] = "Hello World!";
	char	*ptr;
	char	c;

	c = '\0';
	ptr = ft_strchr(s, c);
	printf("Character '%c' is pointing to %p in this string.", c, (char *)ptr);
	return (0);
}
*/
