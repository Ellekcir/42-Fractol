/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:23:42 by rgriffit          #+#    #+#             */
/*   Updated: 2025/02/03 23:13:29 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// Handles the close event (ESC/x button)
// int (*f)(void *param)
// "destroys" image, window and display
// free's the connection and exits
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
		fractal->image.image_ptr);
	mlx_destroy_window(fractal->mlx_connection,
		fractal->mlx_window);
	free(fractal->mlx_connection);
	exit(0);
}

// Key press event handler
// Handles keyboard input for navigation, zoom, and iteration changes.
// keysym: The key pressed by the user
// Re-render the fractal after state changes
int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == KEY_ESCAPE)
		close_handler(fractal);
	else if (keysym == KEY_LEFT)
		fractal->shift_x -= (0.5 * fractal->scale);
	else if (keysym == KEY_RIGHT)
		fractal->shift_x += (0.5 * fractal->scale);
	else if (keysym == KEY_UP)
		fractal->shift_y -= (0.5 * fractal->scale);
	else if (keysym == KEY_DOWN)
		fractal->shift_y += (0.5 * fractal->scale);
	else if (keysym == KEY_C)
		fractal->iteration_definition += 10;
	else if (keysym == KEY_D)
		fractal->iteration_definition -= 10;
	else if (keysym == KEY_PLUS)
		fractal->scale *= 0.95;
	else if (keysym == KEY_MINUS)
		fractal->scale *= 1.05;
	render_fractal(fractal);
	return (0);
}

// Mouse event handler
// Handles mouse wheel input for zooming in and out.
// button: The mouse button pressed (e.g., 
//Button4 for zoom in, Button5 for zoom out)
// x, y: Mouse coordinates
// Re-render the fractal after zoom changes
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == MOUSE_ZOOM_OUT)
		fractal->scale *= 0.95;
	else if (button == MOUSE_ZOOM_IN)
		fractal->scale *= 1.05;
	render_fractal(fractal);
	return (0);
}

// Mouse tracking for Julia set
// Dynamically updates the Julia set parameters based on mouse movement.
// x, y: Mouse coordinates
// int	julia(int x, int y, t_fractal *fractal)
// {
// 	if (!ft_strncmp(fractal->name, "julia", 5))
// 	{
// 		fractal->julia_x = (map(x, fractal)
// 				* fractal->zoom) + fractal->shift_x;
// 		fractal->julia_y = (map(y, fractal)
// 				* fractal->zoom) + fractal->shift_y;
// 		render_fractal(fractal);
// 	}
// 	return (0);
// }
