/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:23:42 by rgriffit          #+#    #+#             */
/*   Updated: 2025/01/31 21:03:05 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NORMINETTE CHECKED

#include "../inc/fractol.h"

// Error Message - User instruction
void	error_params(void)
{
	ft_printf("Usage:\n\n");
	ft_printf("\t\"./fractol mandelbrot\"\n");
	ft_printf("\tOR\n");
	ft_printf("\t\"./fractol julia <value_1> <value_2>\"\n\n");
	ft_printf("Note: The values represent the coordinates of ");
	ft_printf("a point in the complex plane.\n");
	exit(EXIT_FAILURE);
}

// Error Message - Malloc fail
void	error_malloc(void)
{
	perror("Problems with Malloc");
	exit(EXIT_FAILURE);
}
