/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:12:25 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/23 14:36:37 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Handle various conversions -
// %c: Print a single character.
// %s: Print a string.
// %p: Print the void pointer argument in hexadecimal format.
// %d, %i: Print integers in base 10.
// %u: Print unsigned decimal numbers.
// %x: Print numbers in hexadecimal (lowercase) format.
// %X: Print numbers in hexadecimal (uppercase) format.
// %%: Print a percent sign.

static int	ft_check_format_specifier(va_list args, char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_printint(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_printunsignedint(va_arg(args, unsigned int));
	else if (specifier == 'p')
		count += ft_printptr(va_arg(args, void *));
	else if (specifier == 'x')
		count += ft_printhex(va_arg(args, unsigned int), specifier);
	else if (specifier == 'X')
		count += ft_printhex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		count += ft_printchar('%');
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (str == NULL)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			count += ft_check_format_specifier(args, str[i]);
		}
		else
		{
			count += ft_printchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
