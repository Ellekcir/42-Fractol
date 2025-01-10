/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:24:20 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/31 04:17:33 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
     The strnstr() function locates
     the first occurrence of the
     null-terminated string needle in
     the string haystack, where not
     more than len characters are
     searched.  Characters that
     appear after a `\0' character
     are not searched.

RETURN:
     If needle is an empty string,
     haystack is returned; if needle
     occurs nowhere in haystack, NULL
     is returned; otherwise a pointer
     to the first character of the
     first occurrence of needle is
     returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && i + j < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s1;
	const char	*s2;
	size_t		len;
	int			result;

	s1 = "Hello";
	s2 = "Help!";
	len = 5;
	result = ft_strnstr(s1, s2, len);
	printf("%d is the result.\n\n", result);
	if (result < 0)
	{
		printf("'%s' is less than '%s'\n", s1, s2);
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
