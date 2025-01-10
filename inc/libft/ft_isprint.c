/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:00:07 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/22 15:23:02 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("Character is not printable if the 
	ASCII (decimal) value is a command equiv. 
eg: esc (27)\n3: %d\n\n", ft_isprint(3));
	printf("The character is printable if its 
	ASCII (decimal) value is greater than 31 
	and less than 127\n'3':  %d\n\n", ft_isprint('3'));
}
*/
