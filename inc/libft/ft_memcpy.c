/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:54:27 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 03:33:33 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
     The memcpy() function copies n bytes from memory area src 
     to memory area dst.
     If dst and src overlap, behavior is undefined.  
     Applications in which dst and
     src might overlap should use memmove(3) instead.
RETURN:
     The memcpy() function returns the original value of dst.	
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (d != NULL || s != NULL)
			d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "Hello World";
	char	dst[20];
	ft_memcpy(dst, src, 13);
	//memcpy(dst, src, 13);
	printf("Copied string: %s\n", dst);
	return (0);
}
*/
