/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:48:03 by rgriffit          #+#    #+#             */
/*   Updated: 2024/04/02 15:48:06 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
s: The string to output.
fd: The file descriptor on which to write.
Outputs the string 's' to the given file descriptor. 
Followed by a newline
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
int	main(void)
{
	int fd = 1;

	ft_putendl_fd("Hello Possum!", fd);
	return(0);
}
*/