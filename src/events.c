/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:23:42 by rgriffit          #+#    #+#             */
/*   Updated: 2025/01/31 21:46:52 by rgriffit         ###   ########.fr       */
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
#ifdef __linux__
	mlx_destroy_display(fractal->mlx_connection);
#endif
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
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == KEY_RIGHT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == KEY_UP)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == KEY_DOWN)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == KEY_PLUS)
		fractal->iteration_definition += 10;
	else if (keysym == KEY_MINUS)
		fractal->iteration_definition -= 10;
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
		fractal->zoom *= 0.95;
	else if (button == MOUSE_ZOOM_IN)
		fractal->zoom *= 1.05;
	render_fractal(fractal);
	return (0);
}

// Mouse tracking for Julia set
// Dynamically updates the Julia set parameters based on mouse movement.
// x, y: Mouse coordinates
int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, 0, WIDTH)
				* fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, 0, HEIGHT)
				* fractal->zoom) + fractal->shift_y;
		render_fractal(fractal);
	}
	return (0);
}
