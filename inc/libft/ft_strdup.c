/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 04:21:36 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/31 04:46:31 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strdup() function allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it.  The pointer
     may subsequently be used as an argument to the function free(3).
     The free() function frees allocations that were created via the pre-
     ceding allocation functions.
     The free() function deallocates the memory allocation pointed to by
     ptr. If ptr is a NULL pointer, no operation is performed.

     If insufficient memory is available, NULL is returned and errno is
     set to ENOMEM.

     The strndup() function copies at most n characters from the string s1
     always NUL terminating the copied string.
*/

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = 0;
	while (str[len])
		len++;
	dup = (char *)malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>

int main(void)
{
    const char *OG = "Hello Possum";
    char *DUP = ft_strdup(OG);
    
    printf("Original string: %s\n", OG);
    printf("Duplicate string: %s\n", DUP);
    return (0);
}
*/
