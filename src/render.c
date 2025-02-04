/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:39:34 by rgriffit          #+#    #+#             */
/*   Updated: 2025/02/04 11:34:33 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// Put a pixel in the image buffer this is to create a whole image 
// before pushing it to the window to make it more seemless.
static void	my_pixel_put(int x_pixel, int y_pixel, t_image *image, int colour)
{
	int	offset;

	offset = (y_pixel * image->line_length) + (x_pixel * (image->bpp / 8));
	*(unsigned int *)(image->pixels_ptr + offset) = colour;
}

// toggle between Mandelbrot and Julia set.
// For Julia, use the pre-defined Julia parameters at start of program
// For Mandelbrot, use the current pizels point in the complex plane
static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->re_x = fractal->julia_x;
		c->im_y = fractal->julia_y;
	}
	else
	{
		c->re_x = z->re_x;
		c->im_y = z->im_y;
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
		 
 maps the pixel position to the complex plane, iterates using the 
 Mandelbrot or Julia formula, and assigns a color based on the 
 number of iterations before divergence (exits stable area).
 
z = sum_complex(square_complex(z), c);
z = z^2 + c
*/
static	void	handle_pixel(int x_pixel, int y_pixel, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	i = 0;
	z.re_x = (map(x_pixel, fractal) * fractal->scale) + fractal->shift_x;
	z.im_y = (map(y_pixel, fractal) * fractal->scale) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iteration_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.re_x * z.re_x) + (z.im_y * z.im_y) > fractal->map_boundary)
		{
			colour = add_colour(i, fractal->iteration_definition);
			my_pixel_put(x_pixel, y_pixel, &fractal->image, colour);
			return ;
		}
		++i;
	}
	my_pixel_put(x_pixel, y_pixel, &fractal->image, BLACK);
}

// Iterates through each pixel, calculates its value, and displays 
// the rendered image in the MLX window AFTER the entire 
// image is created.
void	render_fractal(t_fractal *fractal)
{
	int		x_pixel;
	int		y_pixel;

	y_pixel = -1;
	while (++y_pixel < HEIGHT)
	{
		x_pixel = -1;
		while (++x_pixel < WIDTH)
		{
			handle_pixel(x_pixel, y_pixel, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->image.image_ptr, 0, 0);
}
