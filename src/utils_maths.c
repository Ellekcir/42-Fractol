#include "../inc/fractol.h"


// RESCALE MAP 800 PIXELS SCALED INTO XY(-2, 2)
//((2 - (-2)) / 799) * (x - 0) / (799 - 0) + (-2))

double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}
// SUM COMPLEX
// (a + i) + (c + di) = (a + c) + (b + d)i
t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

// SQUARE A COMPLEX NUMBER
// (x + yi) * (x + yi)
// x^2 + xyi + xyi + y^2i^2
//i^2 = -1
//x^2 + 2xyi + y^2 * -1
//x^2 - y^2 + 2xyi
// real (x) = (x^2 - y^2)
// imag (y) = 2 * x * y

t_complex	square_complex(t_complex z)
{
	t_complex	result;
	
	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);


}