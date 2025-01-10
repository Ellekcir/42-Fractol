/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:25:30 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 16:42:31 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
	 The strcmp() and strncmp() func-
     tions lexicographically compare
     the null-terminated strings s1
     and s2.

     The strncmp() function compares
     not more than n characters.
     Because strncmp() is designed
     for comparing strings rather
     than binary data, characters
     that appear after a `\0' charac-
     ter are not compared.
RETURN:
     The strcmp() and strncmp() func-
     tions return an integer greater
     than, equal to, or less than 0,
     according as the string s1 is
     greater than, equal to, or less
     than the string s2.  The compar-
     ison is done using unsigned
     characters, so that `\200' is
     greater than `\0'.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s1;
	const char	*s2;
	size_t		n;	
	int			result;

	s1 = "Apple";
	s2 = "apple";
	n = 5;
	result = ft_strncmp(s1, s2, n);
	if (result < 0)
	{
		printf("'%s' is less than '%s'\n", s1, s2);
		printf("'A' equals ACSII value 65\n");
		printf("'a' equals ACSII value 97\n");

	}
	else if (result > 0)
	{
		printf("'%s' is greater than '%s'\n", s1, s2);
	}
	else
	{
		printf("'%s' is equal to '%s'\n", s1, s2);
	}
	return (0);
}
*/
