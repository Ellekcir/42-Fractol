/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:23:42 by rgriffit          #+#    #+#             */
/*   Updated: 2025/01/10 23:45:10 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	error_params(void)
{
	ft_printf("Please enter \n\n\t\"./fractol mandelbrot\"\nor\n\t\"./fractol julia <value_1> <value_2>\"\n\n The values will be the two coordinates of the point in the complex plane.");
	exit(1);
}

void	error_malloc(void)
{
	perror("Problems with Malloc");
	exit(1);
}