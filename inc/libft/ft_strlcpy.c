/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:25:53 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/31 04:13:42 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
	The strlcpy() function is designed to copy strings while guaranteeing
	NUL-termination and preventing buffer overflow. Copies up to dstsize - 1 
	characters from the source string src to the destination buffer dst. 
	Ensures that the resulting string in dst is always NUL-terminated.
RETURN:
	Returns the total length of the source string that was supposed to be
	copied (not including the NUL terminator).
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*src;
	char	dst[20];
	size_t		size;

	src = "Hello Possum!";
	size = sizeof(dst);
	printf("Length of copied string: %zu\n", ft_strlcpy(dst, src, size));
	printf("Copied string: %s\n", dst);
	return (0);
}
*/
