/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:18:15 by rgriffit          #+#    #+#             */
/*   Updated: 2024/04/01 12:35:55 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
The ft_striteri function iterates over each character in the input string s 
and applies the function f to each character along with its corresponding index.
RETURN:
NONE
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
/*
#include <stdio.h>

int	main()
{
	char *s = "Hello Possum!";

	printf("Original String: %s\n", s);
	ft_striteri(s, ft_putstr_fd(s, 1));
	return (0);
}
*/
