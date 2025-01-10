/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:10:23 by rgriffit          #+#    #+#             */
/*   Updated: 2024/04/05 03:48:47 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DEFINITION:
Allocates space to the memory using the function malloc(3)
and returns a new string, which is the result of s1 & s2 being concatenated.
RETURN:
The new string (s1 & s2 concatenated), NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL || !s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*result;

	s1 = "Hello ";
	s2 = "Possum!";
	result = ft_strjoin(s1, s2);
	printf("s1: %s \n s2: %s \n", s1, s2);
	printf("Joined strings: %s", result);
	free((void *)result);
	return (0);
}
*/
