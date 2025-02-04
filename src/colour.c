/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:38:08 by rgriffit          #+#    #+#             */
/*   Updated: 2025/02/04 13:16:33 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
// iteration:
// The current iteration count (how many times the point was tested).
// max_iterations:
// The maximum number of iterationsto test before deciding that the 
// point is in the set.
// Returns: A 24-bit RGB color in hexadecimal format (0xRRGGBB)
// The multiplication by 6.0 ensures that the sine waves 
// complete a full cycle, covering all rainbow colors.

//////////////////// VIBRANT COLOUR ////////////////////
// int	add_colour(int iteration, int max_iterations)
// {
// 	double	t;
// 	int		red;
// 	int		green;
// 	int		blue;

// 	if (iteration == max_iterations)
// 		return (BLACK);
// 	t = (double)iteration / max_iterations * 6.0;
// 	red = (int)(sin(t) * 127 + 128);
// 	green = (int)(sin(t + 2) * 127 + 128);
// 	blue = (int)(sin(t + 4) * 127 + 128);
// 	return ((red << 16) | (green << 8) | blue);
// }

//////////////// BLACK & WHITE ///////////////////////
// int	add_colour(int iteration, int max_iterations)
// {
// 	int	gray;

// 	if (iteration == max_iterations)
// 		return (BLACK);
// 	gray = (255 * iteration) / max_iterations;
// 	return ((gray << 16) | (gray << 8) | gray);
// }

//////////////////// FLOOR IS LAVA ////////////////////
int	add_colour(int iteration, int max_iterations)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	if (iteration == max_iterations)
		return (BLACK);
	t = (double)iteration / max_iterations;
	red = (int)(255 * t);
	green = (int)(255 * pow(t, 1.5));
	blue = (int)(50 * pow(t, 3));
	return ((red << 16) | (green << 8) | blue);
}

////////////////////// RAINBOW ////////////////////////
/*
		0x1a1a1a, // Dark gray
		0x004d99, // Deep blue
		0x0099ff, // Sky blue
		0x33cc33, // Green
		0xffff00, // Yellow
		0xff8000, // Orange
		0xff0000, // Red
		0x99004d  // Dark pink
		
		0x0d0d0d, // Very Dark Gray  
		0x1f3d7a, // Navy Blue  
		0x2a75c4, // Medium Blue  
		0x33a3ff, // Light Blue  
		0x66cc66, // Soft Green  
		0xffcc00, // Golden Yellow  
		0xff6600, // Vivid Orange  
		0xcc0033  // Deep
*/
// int	add_colour(int iteration, int max_iterations)
// {
// 	int	color_palette[] = 
// 	{
// 		0x1a1a1a,
// 		0x004d99,
// 		0x0099ff,
// 		0x33cc33,
// 		0xffff00,
// 		0xff8000,
// 		0xff0000,
// 		0x99004d
// 	};
// 	int palette_size;
// 	palette_size = sizeof(color_palette) / sizeof(color_palette[0]);
// 	if (iteration == max_iterations)
// 		return (BLACK);
// 	return (color_palette[iteration % palette_size]);
// }
