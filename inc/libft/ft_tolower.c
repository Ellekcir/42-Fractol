/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:23:56 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 04:08:00 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
	Converts an uppercase letter to its corresponding lowercase letter.
RETURN:
	The lowercase version of the character c if it is an uppercase letter.
	Otherwise, it returns c unchanged.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>

int main()
{
	char	c = 'A';
	
	printf("Original character: %c\n", c);
	printf("Lowercase character: %c\n", ft_tolower(c));

    return (0);
}
*/
