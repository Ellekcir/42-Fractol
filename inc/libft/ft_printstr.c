/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:13:56 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/22 04:57:44 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	if (str == 0)
	{
		count += ft_printstr("(null)");
		return (count);
	}
	while (str[count] != '\0')
	{
		ft_printchar(str[count]);
		count++;
	}
	return (count);
}
