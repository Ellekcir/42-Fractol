/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:54:56 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/31 16:55:03 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen2(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr2(char *content, int c)
{
	int	i;

	i = 0;
	if (content == NULL)
		return (NULL);
	while (content[i] != '\0')
	{
		if (content[i] == (unsigned char)c)
			return ((char *)&content[i] + 1);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&content[i]);
	return (NULL);
}

char	*ft_strjoin2(char *c, char *b)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!c && !b)
		return (NULL);
	result = (char *)malloc(sizeof(char) * ft_strlen(b) + ft_strlen(c) + 1);
	if (result == NULL)
	{
		free(c);
		return (NULL);
	}
	i = -1;
	while (c[++i] != '\0')
	{
		result[i] = c[i];
	}
	j = 0;
	while (b[j] != '\0')
	{
		result[i++] = b[j++];
	}
	result[i] = '\0';
	free(c);
	return (result);
}

char	*ft_strdup2(char *s1)
{
	int		i;
	int		length;
	char	*s2;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	length = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * length + 1);
	if (!s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
