/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:23:42 by rgriffit          #+#    #+#             */
/*   Updated: 2025/01/22 19:47:44 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// RESCALES THE MAP 800x800 PIXELS SCALED INTO XY(-2, 2)
//((2 - (-2)) / 799) * (x - 0) / (799 - 0) + (-2))
double	map(double unscaled_num, double new_min,
		double new_max, double old_min, double old_max)
{
	double	resolution;

	resolution = ((new_max - new_min) * (unscaled_num - old_min)
			/ (old_max - old_min) + new_min);
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
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	c;

	c.x = z1.x + z2.x;
	c.y = z1.y + z2.y;
	return (c);
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
t_complex	square_complex(t_complex z)
{
	t_complex	c;

	c.x = (z.x * z.x) - (z.y * z.y);
	c.y = 2 * z.x * z.y;
	return (c);
}
