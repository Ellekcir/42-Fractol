#include "../inc/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;
	
	to_lowercase(argv[1]);
	if ((2 == argc && !ft_strncmp2(argv[1], "mandelbrot", 10))
		||(4 == argc && !ft_strncmp2(argv[1], "julia", 5)))
	{
		fractal->name = argv[1];
		printf("SUCCESFUL INPUT ENTERED");
		init_fractal(&fractal);
		fractal_render(&fractal);
		mxl_loop(fractal.mlx_connection);
		return (0);
	}
	else
	{
		error_params();
		exit(EXIT_FAILURE);
	}
}