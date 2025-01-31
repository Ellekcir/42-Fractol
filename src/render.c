/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:39:34 by rgriffit          #+#    #+#             */
/*   Updated: 2025/01/22 19:47:08 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// Put a pixel in the image buffer this is to create a whole image before pushing it to the window to make it more seemless
// Converts x, y coordinates to the pixel's memory location and assigns the color.

static void	my_pixel_put(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->line_length) + (x * (image->bpp / 8));
	*(unsigned int *)(image->pixels_ptr + offset) = color;
}

// toggle between Mandelbrot and Julia set.
// For Julia, use the pre-defined Julia parameters at start of program
// For Mandelbrot, use the current pizels point in the complex plane
static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

/*
		0------800  -2-----+2
		|		|	|		|
	800	|		|	|		|
		|		|	|		|
		 -------	 -------

		 MANDELBROT
		 z = z^2 + c
		 z initially is (0, 0)
		 c is the point in the complex plane
		 
 maps the pixel position to the complex plane, iterates using the Mandelbrot or Julia formula, and assigns a color based on the number of iterations before divergence.
*/
static	void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	i = 0;
	z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iteration_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->chaos_value)
		{
			colour = map(i, BLACK, RED, 0, fractal->iteration_definition);
			my_pixel_put(x, y, &fractal->image, colour);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->image, WHITE);
}

// Iterates through each pixel, calculates its value, and displays the rendered image in the MLX window.
void	render_fractal(t_fractal *fractal)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->image.image_ptr, 0, 0);
}
