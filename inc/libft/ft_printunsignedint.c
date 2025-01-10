/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignedint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:39:22 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/23 14:39:59 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunsignedint(unsigned int number)
{
	int	count;

	count = 0;
	if (number >= 10)
	{
		count += ft_printunsignedint(number / 10);
		count += ft_printchar((number % 10) + '0');
	}
	else
		count += ft_printchar(number + '0');
	return (count);
}
