/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 04:53:56 by rgriffit          #+#    #+#             */
/*   Updated: 2024/04/01 06:45:52 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEFINITION:
Allocates memory using malloc function, and returns a 
substring from the string 's', the substring will begin
at the index 'start' and is of maximum size 'len'. 
RETURN:
The substring shall be returned and NULL if the allocation fails. 
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		slen;
	size_t		i;

	slen = 0;
	while (s[slen] != '\0')
		slen++;
	if (start > slen)
		len = 0;
	if (len > (slen - start))
		len = slen - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL || s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char const		*str;
	size_t			len;
	unsigned int	start;

	str = "Hello Possum!";
	start = 6;
	len = 7;
	printf("%s\n", ft_substr(str, start, len));
}
*/
