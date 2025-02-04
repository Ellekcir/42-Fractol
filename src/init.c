/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:55:46 by rgriffit          #+#    #+#             */
/*   Updated: 2025/02/04 12:30:36 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// Initialises the events for the fractal 
// basically listens for only key presses, 
// mouse clicks and window close
static void	init_events(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,
		2, 1L << 0, key_handler, fractal);
	mlx_hook(fractal->mlx_window,
		4, 1L << 2, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window,
		17, 0, close_handler, fractal);
}

// Initialises the data for the fractal
static void	init_data(t_fractal *fractal)
{
	fractal->map_boundary = 4;
	fractal->iteration_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->scale = 1.0;
	fractal->cx = 0;
	fractal->cy = 0;
	fractal->map.new_min = NEW_MIN;
	fractal->map.new_max = NEW_MAX;
	fractal->map.old_min = OG_MIN;
	fractal->map.old_max = OG_MAX;
}

// Initialises the fractal, sets up the window, image and pixels
void	init_fractal(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		error_malloc();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, "Fract-ol");
	if (fractal->mlx_window == NULL)
	{
		free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (fractal->image.image_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		//free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->image.pixels_ptr = mlx_get_data_addr(fractal->image.image_ptr,
			&fractal->image.bpp, &fractal->image.line_length,
			&fractal->image.endian);
	init_data(fractal);
	init_events(fractal);
}
