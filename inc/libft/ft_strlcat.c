/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:15:39 by rgriffit          #+#    #+#             */
/*   Updated: 2024/03/27 02:41:55 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION:
     strlcat() appends string src to the end of dst.
     It will append at most dstsize - strlen(dst) - 1
     characters.  It will then NUL-terminate, unless
     dstsize is 0 or the original dst string was
     longer than dstsize (in practice this should not
     happen as it means that either dstsize is incor-
     rect or that dst is not a proper string).

     If the src and dst strings overlap, the behavior
     is undefined.
RETURN:
    Besides quibbles over the return type (size_t
     versus int) and signal handler safety
     (snprintf(3) is not entirely safe on some sys-
     tems), the following two are equivalent:

           n = strlcpy(dst, src, len);
           n = snprintf(dst, len, "%s", src);

     Like snprintf(3), the strlcpy() and strlcat()
     functions return the total length of the string
     they tried to create.  For strlcpy() that means
     the length of src.  For strlcat() that means the
     initial length of dst plus the length of src.

     If the return value is >= dstsize, the output
     string has been truncated.  It is the caller's
     responsibility to handle this.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
#include <stdio.h>

int main(void)
{
    char dest[20] = "Hello";
    const char *src = " possum!";
    size_t size = sizeof(dest);

    size_t result = ft_strlcat(dest, src, size);

    printf("Concatenated two strings in dest: %s\n", dest);
    printf("Length of concatenated string: %zu\n", result);

    return 0;
}
*/
