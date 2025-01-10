/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:58:58 by rgriffit          #+#    #+#             */
/*   Updated: 2024/04/05 00:29:43 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
Allocate memory using malloc(), and will return a copy of 's1' 
with the characters specified in 'set' removed from the beginning 
and the end of the string. 
RESULT:
The trimmed string. NULL if allocation fails. 
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_str;
	size_t	i;
	size_t	e;

	if (!*s1 || !s1)
		return (ft_strdup(""));
	if (!*set || !s1)
		return (ft_strdup(s1));
	i = 0;
	while (ft_strchr(set, s1[i]) && i < ft_strlen(s1))
		i++;
	e = ft_strlen(s1);
	while (ft_strchr(set, s1[e - 1]) && s1[i] != 0)
		e--;
	trim_str = (char *)malloc(sizeof(char) * (e - i + 1));
	if (trim_str == NULL)
		return (NULL);
	ft_strlcpy(trim_str, &s1[i], (e - i + 1));
	if (trim_str == 0)
		return (NULL);
	return (trim_str);
}
/*
#include <stdio.h>

int    main(void)
{
	char	*original_str;
	char	*remove;
	char	*trimmed_str;
	
	original_str = "  **Hello Possum!   ";
	remove = " !*";
	trimmed_str = ft_strtrim(original_str, remove);
	if (trimmed_str == NULL)
	{
		printf("Memory allocation failed. Unable to trim the string.\n");
		return (1);
	}
	printf("Original string: \"%s\"\n", original_str);
	printf("Trimmed string: \"%s\"\n", trimmed_str);
	free(trimmed_str);
	return (0);
}
*/
