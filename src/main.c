/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:23:42 by rgriffit          #+#    #+#             */
/*   Updated: 2025/02/03 18:46:11 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NORMINETTE CHECKED

#include "../inc/fractol.h"

// Creates a new fractal struct with the given parameters 
// checks the type of fractal and calls the corresponding function to create it
// fractal name is assigned the it shall initiate the fractal 
// render the fractal and loop the connection to keep it running 
// or it it will show an error warning and shut the program.
int	main(int argc, char **argv)
{
	t_fractal		fractal;

	if (argc < 2 || argc > 4)
		error_params();
	to_lowercase(argv[1]);
	if ((2 == argc && !ft_strncmp2(argv[1], "mandelbrot", 10))
		|| (4 == argc && !ft_strncmp2(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp2(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		ft_printf("Starting up Fractol - %s", fractal.name);
		init_fractal(&fractal);
		render_fractal(&fractal);
		mlx_loop(fractal.mlx_connection);
		return (0);
	}
	else
		error_params();
}
