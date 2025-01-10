/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:52:01 by rgriffit          #+#    #+#             */
/*   Updated: 2024/04/05 16:01:13 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The bzero() function writes n zeroed bytes to the string s.  If n is
     zero, bzero() does nothing.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr = '\0';
		ptr++;
	}
}
/*
#include <stdio.h>

int main(void)
{	char	buffer[10]; // Create a buffer to store the memory block
    	size_t	len; // Length of the memory block
	size_t	i; // Loop counter by index
	char	*str;

	len = 10;
    	i = 0;
	str = "Hello";

    // Putting a string to the buffer
    printf("Setting value to the memory: 'Hello' followed by 'X's\n");
    while (i < len - 1 && str[i] != '\0')
    {
        buffer[i] = str[i];
        i++;
    }
    while (i < len)
    {
	    buffer[i] = 'X';
	    i++;
    }
    printf("Memory block contents: %s\n", buffer);

    // Clear the memory block using ft_bzero
    printf("\nUsing ft_bzero: Clearing memory block\n");
    ft_bzero(buffer, len);
    printf("Memory block contents after clearing: %s\n", buffer);

    return (0);
}
*/
