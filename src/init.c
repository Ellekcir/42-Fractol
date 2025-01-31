/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:23:42 by rgriffit          #+#    #+#             */
/*   Updated: 2025/01/17 19:37:40 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// /* 
// INIT -
// MLX 
// LISTENING EVENTS
// HOOKS DATA
// */
// fractal->chaos_value = 4; // 2 ^ 2 out side of the circle is when the numbers become unstable where as the ones inside the boundaries of the mandelbrot are stable.
// The higher the fractal->iteration_definition = 42;  is set the more detailed the image will be
static void	init_data(t_fractal *fractal)
{
	fractal->chaos_value = 4;
	fractal->iteration_definition = 42; 
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	init_events(t_fractal *fractal)
{
	// Handle key press events
	mlx_hook(fractal->mlx_window, 
	#ifdef __linux__
			KeyPress, KeyPressMask,key_handler, fractal
	#elif __APPLE__
			2, 1L << 0, key_handler, fractal
	#endif
	);
	// Handle mouse button press events
	mlx_hook(fractal->mlx_window, 
	#ifdef __linux__
			ButtonPress, ButtonPressMask,
	#elif __APPLE__
			4, 1L << 2,
	#endif
			mouse_handler, fractal);

	// Handle window close events
	mlx_hook(fractal->mlx_window, 
	#ifdef __linux__
			DestroyNotify, StructureNotifyMask,
	#elif __APPLE__
			17, 0,
	#endif
			close_handler, fractal);

	// Handle pointer motion (for real-time Julia tracking)
	mlx_hook(fractal->mlx_window, 
	#ifdef __linux__
			MotionNotify, PointerMotionMask,
	#elif __APPLE__
			6, 1L << 6,
	#endif
			julia_track, fractal);
}

// Creates mlx connection - mlx_init();
// Creates window - mlx_new_window();
// if the window or connection is created and
// fails it will "destory" and free itself and
// throw an error in regards to malloc
void	init_fractal(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		error_malloc(); 
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		#ifdef __linux__
		mlx_destroy_display(fractal->mlx_connection);
		#endif
		free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->image.image_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		#ifdef __linux__
		mlx_destroy_display(fractal->mlx_connection);
		#endif
		free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->image.pixels_ptr = mlx_get_data_addr(fractal->image.image_ptr, 
	&fractal->image.bpp, &fractal->image.line_length, &fractal->image.endian);
	
	init_events(fractal);
	init_data(fractal);
}