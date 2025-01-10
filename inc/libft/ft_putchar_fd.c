/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:15:03 by rgriffit          #+#    #+#             */
/*   Updated: 2024/04/01 11:32:14 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
c: The character to output.
fd: The file descriptor on which to write.
Outputs the character 'c' to the given file descriptor. 
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <stdio.h>

int	main()
{
	char c = 'A';
	int fd = 1;

	printf("\n\nWrites character: %c, with the file descriptor: %d.\n", c, fd);
	// 1 - represets the process's standard output (eg console output).
	// 2 - process's standard error stream (eg error messages).
	// 0 - process's standard input stream (eg keyboard input).
	ft_putchar_fd(c, fd);
	return (0);
}
*/
