/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:23:42 by rgriffit          #+#    #+#             */
/*   Updated: 2025/02/04 11:59:54 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// RESCALES THE MAP 800x800 PIXELS SCALED INTO XY(-2, 2)
//((2 - (-2)) / 799) * (x - 0) / (799 - 0) + (-2))
double	map(double unscaled_num, t_fractal *fractal)
{
	double	resolution;

	resolution = ((fractal->map.new_max - fractal->map.new_min)
			* (unscaled_num - fractal->map.old_min)
			/ (fractal->map.old_max - fractal->map.old_min)
			+ fractal->map.new_min);
	return (resolution);
}

// SUM COMPLEX
// (a + i) + (c + di) = (a + c) + (b + d)i
// Complex Numbers:
// Represented as z = x + yi
// x = real part of the complex number
// y Imainary part of the complex number
// z^1 = x^1 + y^1i,
// z^2 = x^2 + y^2i 
// To add complex numbers, add their real parts 
// and their imaginary parts separately
// z^1 + z ^2 = (x^1 + x^2) + (y^1 + y^2)i
// ADDS THE (RE_X) REAL PARTS AND (IM_Y) IMAGINARY PARTS
t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	complex_sum;

	complex_sum.re_x = z.re_x + c.re_x;
	complex_sum.im_y = z.im_y + c.im_y;
	return (complex_sum);
}

// SQUARE A COMPLEX NUMBER
// z = complex number
// z^2 = (x + yi) * (x + yi)
// z^2 + x^2 + 2xyi + y^2i^2
// RULE WHEN USIING COMPLEX NUMBERS 
// i^2 = -1
//	z^2 = x^2 - y^2 +2xyi
// real (x) = (x^2 - y^2)
// imag (y) = 2 * x * y
// squared real (x) = (x^2 - yi^2)
t_complex	square_complex(t_complex z)
{
	t_complex	complex_squared;

	complex_squared.re_x = (z.re_x * z.re_x) - (z.im_y * z.im_y);
	complex_squared.im_y = 2 * z.re_x * z.im_y;
	return (complex_squared);
}
