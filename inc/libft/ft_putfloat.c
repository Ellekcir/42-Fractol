/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:59:26 by rgriffit          #+#    #+#             */
/*   Updated: 2025/02/03 18:26:51 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat(double n, int decimal_places)
{
	long long	whole_part;
	double		decimal;
	long long	decimal_part;
	int			i;

	whole_part = (long long)n;
	decimal = n - whole_part;
	if (decimal < 0)
	{
		decimal = -decimal;
	}
	ft_putnbr(whole_part);
	ft_putchar('.');
	i = 0;
	while (i < decimal_places)
	{
		decimal *= 10;
		i++;
	}
	decimal_part = (long long)decimal + 0.5;
	ft_putnbr(decimal_part);
}
