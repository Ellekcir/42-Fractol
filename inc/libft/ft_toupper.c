/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:23:39 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 04:09:35 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
	converts a lowercase character to its corresponding uppercase equivalent. 
	It takes a single argument of type int, which represents the character to 
	be converted, and returns the uppercase version of that character if it is 
	a lowercase letter. 
RETURN:
	The uppercase version of the character c if it is a lowercase letter. 
	Otherwise, it returns c unchanged.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>

int main()
{
	char	c = 'a';

	printf("Original character: %c\n", c);
	printf("Uppercase character: %c\n", ft_toupper(c));

    return (0);
}
*/
