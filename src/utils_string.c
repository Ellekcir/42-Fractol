/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:23:42 by rgriffit          #+#    #+#             */
/*   Updated: 2025/02/03 12:02:42 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// String compare with n characters - return 0 if equal
int	ft_strncmp2(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0' && *s2 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}

// Make argument lowercase
void	to_lowercase(char *s)
{
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z')
		{
			*s = *s + ('a' - 'A');
		}
		s++;
	}
}

// ALPHA TO DOUBLE
// similar to atoi, but dealing with floats
// takes the cmnd line args and
// converts to long double (typedef ldbl)
static void	ft_sign(const char *str, int *sign)
{
	*sign = 1;
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
}

double	atodbl(const char *str)
{
	long	whole_part;
	double	decimal_part;
	double	divisor;
	int		sign;

	whole_part = 0;
	decimal_part = 0;
	divisor = 10;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	ft_sign(str, &sign);
	while (*str >= '0' && *str <= '9')
		whole_part = whole_part * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		decimal_part += (*str++ - '0') / divisor;
		divisor *= 10;
	}
	return (sign * (whole_part + decimal_part));
}
