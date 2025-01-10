#include "../inc/fractol.h"

/* 
INIT -
MLX 
LISTENING EVENTS
HOOKS DATA
*/
void	init_data(t_fractal *fractal)
{
	fractal->chaos_value // 2^ 2 hypothenuse
}

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		error_malloc(); //TODO
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->image.image_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->image.pixels_ptr = mlx_get_data_addr(fractal->image.image_ptr, 
	&fractal->image.bpp, &fractal->image.line_length, &fractal->image.endian);

	//TODO
	init_events(fractal);
	init_data(fractal);
}