/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:34:50 by rgriffit          #+#    #+#             */
/*   Updated: 2024/04/01 11:42:49 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
s: The string to output.
fd: The file descriptor on which to write.
Outputs the string 's' to the given file descriptor. 
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	write(fd, s, len);
}
/*
#include <stdio.h>

int	main()
{
	char *s = "Hello Possum!";
	int fd = 3;

	printf("\nWrites string: %s, to the given file descriptor: %d.\n", s, fd);
	ft_putstr_fd(s, fd);
	return (0);
}
*/
