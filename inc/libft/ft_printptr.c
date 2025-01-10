/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:38:03 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/23 14:40:25 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_makehex(size_t p)
{
	int		count;
	char	*hex_values;

	hex_values = "0123456789abcdef";
	count = 0;
	if (p >= 16)
	{
		count += ft_makehex(p / 16);
	}
	count += ft_printchar(hex_values[p % 16]);
	return (count);
}

int	ft_printptr(void *ptr)
{
	size_t	p;
	int		count;

	p = (size_t)ptr;
	count = 2;
	write(1, "0x", 2);
	if (p == 0)
	{
		write(1, "0", 1);
		count += 1;
		return (count);
	}
	count += ft_makehex(p);
	return (count);
}
