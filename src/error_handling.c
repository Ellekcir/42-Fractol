/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:23:42 by rgriffit          #+#    #+#             */
/*   Updated: 2025/02/04 12:56:37 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NORMINETTE CHECKED

#include "../inc/fractol.h"

// Error Message - User instruction
void	error_params(void)
{
	ft_printf("Usage:\n\n");
	ft_printf("  \"./fractol mandelbrot\"\n");
	ft_printf("\tOR\n");
	ft_printf("  \"./fractol julia <x co-ordinate> <y co-ordinate>\"\n\n");
	ft_printf("Note: The values given for the x & y co-ordinates ");
	ft_printf("represent a point in the complex plane.\n");
	ft_printf("Use co-ordinates between -2 and 2 for best results. \n");
	exit(EXIT_FAILURE);
}

// Error Message - Malloc fail
void	error_malloc(void)
{
	perror("Problems with Malloc");
	exit(EXIT_FAILURE);
}
