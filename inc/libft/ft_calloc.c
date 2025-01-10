/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 04:51:26 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/31 05:43:08 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The malloc() function allocates size bytes of memory and 
returns apointer to the allocated memory.
The calloc() function contiguously allocates enough space 
for count objects that are size bytes of memory each and 
returns a pointer to the allocated memory.  The allocated 
memory is filled with bytes of value zero. For example, if 
you want to allocate memory for 5 integers, you would call 
calloc(5, sizeof(int)). This would allocate memory for an array 
of 5 integers, with each integer initialized to zero. In summary, c
alloc helps allocate memory for arrays and ensures that the allocated 
memory is initialized to zero.

The free() function deallocates the memory allocation pointed to by 
ptr. If ptr is a NULL pointer, no operation is performed.

RETURN VALUES
If successful, calloc(), malloc(), realloc(), reallocf(), and
valloc() functions return a pointer to allocated memory.  
If there is an error, they return a NULL pointer and set errno to 
ENOMEM. The free() function does not return a value.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			sizeofmemtoalloc;
	void			*ptr;
	unsigned char	*bytesptr;
	size_t			i;

	sizeofmemtoalloc = (count * size);
	ptr = malloc(sizeofmemtoalloc);
	if (ptr == NULL)
		return (NULL);
	if (ptr != NULL)
		bytesptr = (unsigned char *)ptr;
	i = 0;
	while (i < sizeofmemtoalloc)
	{
		bytesptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	int *arr = (int *)ft_calloc(5, sizeof(int));
	if (!arr)
		return (1);
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
	free(arr);
	return (0);
}
*/