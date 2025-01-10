/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:24 by rgriffit          #+#    #+#             */
/*   Updated: 2024/04/02 17:24:53 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
     The strlen() function computes
     the length of the string s.  The
     strnlen() function attempts to
     compute the length of s, but
     never scans beyond the first
     maxlen bytes of s.
RETURN:
     The strlen() function returns
     the number of characters that
     precede the terminating NUL
     character.  The strnlen() func-
     tion returns either the same
     result as strlen() or maxlen,
     whichever is smaller.
*/

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	char *str;
	str = "Teststring";

	printf("Calculates the length of a string. %zu", ft_strlen(str));
}
*/
