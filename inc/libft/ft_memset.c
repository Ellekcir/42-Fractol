/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:46:31 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 00:33:05 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
     The memset() function
     writes len bytes of value c
     (converted to an unsigned
     char) to the string b.
RETURN:
     The memset() function
     returns its first argument.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptrtomem;
	size_t			i;

	ptrtomem = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptrtomem[i] = c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>

int	main(void)
{
	char	b[] = "Hello World!";
	char	c;

	c = 'x';
	ft_memset(b + 6, c, 5);
	printf("Modified String: %s\n", b);
	return (0);
}
*/
