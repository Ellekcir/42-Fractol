/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:24:53 by rgriffit          #+#    #+#             */
/*   Updated: 2024/04/05 15:10:46 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
     The strchr() function locates
     the first occurrence of c (con-
     verted to a char) in the string
     pointed to by s.  The terminat-
     ing null character is considered
     to be part of the string; there-
     fore if c is `\0', the functions
     locate the terminating `\0'.

     The strrchr() function is iden-
     tical to strchr(), except it
     locates the last occurrence of
     c.
RETURN:
     The functions strchr() and
     strrchr() return a pointer to
     the located character, or NULL
     if the character does not appear
     in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	if (c == '\0')
		return ((char *)str + len);
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return ((char *)str + len);
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*str;
	char		*result;
	int			c;

	str = "Hello Possum!";
	c = 'o';
	result = ft_strrchr(str, c);
	printf("Character '%c' found at position: %ld \n", c, result - str);
	return (0);
}
*/
