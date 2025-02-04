/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:20:45 by rgriffit          #+#    #+#             */
/*   Updated: 2025/02/03 22:46:07 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// Math functions
# include <math.h>
// open -filecontrols
# include <fcntl.h>
// close, read, write -systemcalls
# include <unistd.h>
// malloc, free, exit -memory management
# include <stdlib.h>
// perror -I/O functions
# include <stdio.h>
// strerror - String functions
# include <string.h>  
// libft
# include "../inc/libft/libft.h"
// mlx library
# include "../inc/mlx_opengl/mlx.h"

# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1
/*
PARAMETERS ERROR MESSAGE ALTERNATIVE

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\"\nor\n\t\".
/fractol julia <value_1> <value_2>\"\n The values will be the two coordinates
 of the point in the complex plane."
*/
# define WIDTH			800
# define HEIGHT			800
# define OG_MIN			0
# define OG_MAX			799
# define NEW_MAX		2
# define NEW_MIN		-2
// COLOURS
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define GREEN			0x00FF00 
# define BLUE			0x0000FF

// https://eastmanreference.com/complete-list-of-applescript-key-codes
# define KEY_ESCAPE		53
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_PLUS		24
# define KEY_MINUS		27
# define MOUSE_ZOOM_IN	4
# define MOUSE_ZOOM_OUT	5
# define KEY_SPACE		49
# define KEY_C			8
# define KEY_D			2

/*
COMPLEX VALUE
	double	x;
	>>> real number
	double	y;
	>>> imaginary number
*/
typedef struct s_complex
{
	double	re_x;
	double	im_y;
}				t_complex;

/* 
IMAGE
// pixels buffer using the mlx values from mlx_get_data_address();
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
typedef struct s_image
{
	void	*image_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_length;
}				t_image;

typedef struct s_map
{
	double	new_max;
	double	new_min;
	double	old_max;
	double	old_min;
}	t_map;

/* 
FRACTAL ID 
// links for mlx
// image connection
// hook values
	void	*mlx_connection;
		>>> 	mlx_int();
	void	*mlx_win;
		>>> 	mlc_new_window();
	t_image	image;

	double	chaos_value;
		>>> measures the weather it stays stable by using the
				hypothenuse theorem
	int		iteration_definition;
		>>> 	how many iterations to do which will define 
				the definition/image quality. i.e the greater amount 
				of iterations the more detailed the image will be.
	double	shift_x;
		>>> 	shifts the fractal horizontally
	double	shift_y;
		>>> 	shifts the fractal vertically
	double	zoom;
		>>> 	zooms in/out the fractal
	double	julia_x;
		>>> 	sets the julia constant x
	double	julia_y;
		>>> 	sets the julia constant y
*/
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_image	image;
	t_map	map;
	double	map_boundary;
	int		iteration_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	double	scale;
	double	x;
	double	y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
}				t_fractal;

// Initialises a fractal
void		init_fractal(t_fractal *fractal);
// renders Fractal
void		render_fractal(t_fractal *fractal);
/************ utils_string ************/
// Atoi function except alpha is converted to a double
double		atodbl(const char *str);
// makes string lowercase
void		to_lowercase(char *s);
// string compares from a certain point in the string
int			ft_strncmp2(char *s1, char *s2, int n);

/************* utils_maths ************/
// Squares a complex number 
t_complex	square_complex(t_complex z);
// Adds the complex numbers and their real parts
t_complex	sum_complex(t_complex z1, t_complex z2);
// Rescales the resolution and creates the mapping for the image
double		map(double unscaled_num, t_fractal *fractal);

/*********** error_handling **********/
// Error Message - User instruction
void		error_params(void);
// Error formalloc fail
void		error_malloc(void);

/*********** hooks_events **********/
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia(int x, int y, t_fractal *fractal);
/*********** colour **********/
int	add_colour(int iteration, int max_iterations);

#endif
