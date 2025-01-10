/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:10:14 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 01:26:04 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	alpha;
	int	nonalpha;

	alpha = 1;
	nonalpha = 0;
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
		return (nonalpha);
	return (alpha);
}
/*
#include <stdio.h>

int main(void)
{
	int c;

	c = ft_isalpha('s');
	printf("\nString: %d\n", c);
}
*/
