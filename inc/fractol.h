#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
// testing
# include <stdio.h>
// malloc free
# include <stdlib.h>
// write
# include <unistd.h>
// mlx lib
# include "../inc/mlx_linux/mlx.h"
# include "../inc/libft/libft.h"

/*
PARAMETERS ERROR MESSAGE ALTERNATIVE

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\"\nor\n\t\"./fractol julia <value_1> <value_2>\"\n The values will be the two coordinates of the point in the complex plane."
*/
#define WIDTH 800
#define HEIGHT 800

/*
COMPLEX VALUE
	double	x;
	>>> real number
	double	y;
	>>> imaginary number
*/
typedef struct	s_complex
{
	double	x;
	double	y;
	t_complex	c;
}				t_complex;
/* 
IMAGE
	void	*img_ptr; 
		>>>		POINTER TO THE IMAGE
	char	*pixels_ptr;
		>>> 	POINTER TO THE PIXELS
	int		bpp;
		>>> 	BITS PER PIXEL
	int		endian;
		>>> 	ENDIAN
	int		line_length;
		>>> 	LENGTH OF A LINE
*/
typedef	struct	s_image
{
	void	*image_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_length;
}				t_image;

/* 
MLX/FRACTAL
	void	*mlx_connection;
		>>> 	mlx_int();
	void	*mlx_win;
		>>> 	mlc_new_window();
*/

typedef	struct	s_fractal
{
	char	*name;
	// MLX 
	void	*mlx_connection; 
	void	*mlx_window;
	// IMAGE
	t_image	image;
	// Hoooks 		TODO;
	double	chaos_value; // hypothenuse
}				t_fractal;

/*
MATHEMATICS
*/
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

/*
ERROR HANDLING
*/
void	error_params(void);
void	error_malloc(void);

/*
STRING UTILS
*/
int		ft_strncmp2(char *s1, char *s2, int n);
//void	ft_putstr_fd2(char *s, int fd);
void	to_lowercase(char *s);

/*
INIT
*/
void	fractal_init(t_fractal *fractal);



# endif