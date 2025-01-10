/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:54:51 by rgriffit          #+#    #+#             */
/*   Updated: 2024/04/05 14:12:22 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPTION:
Parameters-
n: The integer to convert.
Allocates memory using malloc() and returns a string representing the integer
received as an argument. Negative numbers must be handled. 

RETURN:
The string representing the integer. 
NULL if allocation fails.
*/

#include "libft.h"

static unsigned int	ft_nbrlen(int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*n_str;
	unsigned int	nbr;
	unsigned int	len;

	len = ft_nbrlen(n);
	n_str = (char *)malloc(sizeof(char) * (len + 1));
	if (n_str == NULL)
		return (NULL);
	if (n < 0)
	{
		n_str[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr == 0)
		n_str[0] = '0';
	n_str[len] = '\0';
	while (nbr != 0)
	{
		n_str[len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (n_str);
}
/*
#include <stdio.h>

void test_ft_itoa(int n)
{
	char *result = ft_itoa(n);
	if (result == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	printf("%s\n", result);
	free(result);
}

int main(void)
{
	test_ft_itoa(12345);
	test_ft_itoa(0);
	test_ft_itoa(-123);
	test_ft_itoa(2147483647); // Maximum positive int value
	test_ft_itoa(-2147483648); // Minimum negative int value
	return 0;
}
*/
