/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 03:43:03 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/24 14:13:47 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhex(size_t number, char specifier)
{
	int		count;
	char	*hex_values;

	if (specifier == 'X')
		hex_values = "0123456789ABCDEF";
	else if (specifier == 'x')
		hex_values = "0123456789abcdef";
	else
		return (0);
	count = 0;
	if (number >= 16)
	{
		count += ft_printhex(number / 16, specifier);
		count += ft_printchar(hex_values[number % 16]);
	}
	else
		count += ft_printchar(hex_values[number]);
	return (count);
}
