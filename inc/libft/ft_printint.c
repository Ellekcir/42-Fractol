/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 03:47:45 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/23 14:43:01 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printint(int number)
{
	int	count;

	count = 0;
	if (number == -2147483648)
		count += ft_printstr("-2147483648");
	else if (number < 0)
	{
		count += ft_printchar('-');
		count += ft_printint(-number);
	}
	else if (number >= 10)
	{
		count += ft_printint(number / 10);
		count += ft_printchar((number % 10) + '0');
	}
	else
		count += ft_printchar(number + '0');
	return (count);
}
