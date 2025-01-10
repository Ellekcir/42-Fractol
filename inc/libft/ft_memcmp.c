/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:54:27 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 00:42:16 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION: 	
	The memcmp() function compares byte string s1 against byte string s2.
	Both strings are assumed to be n bytes long.

	RETURN: 	
	The memcmp() function returns zero if the two strings are identical, 
	otherwise returns the difference between the first two differing bytes 
	(treated as unsigned char values, so that `\200' is greater than `\0',
	for example).
	Zero-length strings are always identical.  
	This behavior is not required by C and portable c
	ode should only depend on the sign of the returned value.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello";
	char	str2[] = "Hello";
	char	str3[] = "Hella";


	// Test case 1: Equal strings
	printf("Test case 1: Equal strings\n");
	printf("Expected: 0\n");
	printf("ft_memcmp Result: %d\n", ft_memcmp(str1, str2, 5));
	printf("memcmp Result: %d\n\n", memcmp(str1, str2, 5));

	// Test case 2: Different strings
	printf("Test case 2: Different strings\n");
	printf("Expected: Positive value\n");
	printf("ft_memcmp Result: %d\n", ft_memcmp(str1, str3, 5));
	printf("memcmp Result: %d\n\n", memcmp(str1, str3, 5));

    	return (0);

}
*/
