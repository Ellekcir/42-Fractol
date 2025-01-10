/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 02:46:11 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 03:24:55 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
	The memmove() function copies len bytes from string src to string dst.
	The two strings may overlap; the copy is always done in a 
	non-destructive manner.

RETURN:
	The memmove() function returns the original value of dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (src == NULL && dst == NULL)
		return (NULL);
	i = 0;
	if (s < d)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "Possum";
	char	dst[] = "Hello World!";
	size_t	len = 6;

	//ft_memmove(dst, (src + 6), 5);
	//printf("Copied string: %s\n", dst);

	// Print original strings
	printf("Original strings:\n");
	printf("Source: %s\n", src);
	printf("Destination: %s\n\n", dst);

	// Call ft_memmove to move characters from src to dst
	memmove(dst + 6, src, len);

	// Print modified strings
	printf("Modified strings after using ft_memmove:\n");
	printf("Source: %s\n", src);
	printf("Destination: %s\n\n", dst);
	return (0);
}
*/
