#include "../inc/fractol.h"
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
*/
void	handle_pixel(int x, int y, t_fractal *fractol)
{
	t_complex	z;
	t_complex	c;

	z.x = 0.0;
	z.y = 0.0;
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, +2, -2, 0, HEIGHT);
	while()
	{
		z = sum_complex(square_complex(z), c);
		if (norm_complex(z) > fractal->chaos_value)
	}
}
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
			handle_pixel(x, y, pixel)
		}

	}
}