/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:54:56 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/31 16:55:03 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************************************************************

Function name:	get_next_line
Prototype:		char *get_next_line(int fd);
Turn in files:	get_next_line.c, get_next_line_utils.c, get_next_line.h
Parameters:		fd: The file descriptor to read from
Return value:	Read line: correct behavior
				Null: there is nothing else to read, or an error occured
Functions:		read, malloc, free
Description:	Write a function that returns a line read from a file descriptor

************************************************************************** */

#include "libft.h"

char	*ft_update_contents_for_next_call(char *content)
{
	char	*updated_content;

	if (content == NULL)
		return (NULL);
	if (!ft_strchr(content, '\n'))
	{
		free(content);
		return (NULL);
	}
	updated_content = ft_strchr(content, '\n');
	updated_content = ft_strdup(updated_content);
	free(content);
	return (updated_content);
}

char	*ft_extract_line(char *content)
{
	char	*line;
	char	*new_line_char;
	int		i;

	i = 0;
	if (content[i] == '\0')
		return (NULL);
	new_line_char = ft_strchr(content, '\n');
	if (new_line_char == NULL)
		line = ft_strdup(content);
	else
	{
		line = (char *)malloc(new_line_char - content + (sizeof(char) * 1));
		if (line == NULL)
			return (NULL);
		while (content[i] != '\n')
		{
			line[i] = content[i];
			i++;
		}
		line[i] = content[i];
		line[i + 1] = '\0';
	}
	return (line);
}

char	*ft_read_line_to_content(int fd, char *content)
{
	char	*buffer;
	int		count_of_chars_read;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
	{
		free(content);
		return (NULL);
	}
	count_of_chars_read = 1;
	while (content != 0 && !ft_strchr(content, '\n') && count_of_chars_read > 0)
	{
		count_of_chars_read = read(fd, buffer, BUFFER_SIZE);
		if (count_of_chars_read < 0)
		{
			free(buffer);
			free(content);
			return (NULL);
		}
		buffer[count_of_chars_read] = '\0';
		content = ft_strjoin(content, buffer);
	}
	free(buffer);
	return (content);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (content == NULL)
	{
		content = (char *)malloc(sizeof(char) * 1);
		if (content == NULL)
			return (NULL);
		content[0] = '\0';
	}
	content = ft_read_line_to_content(fd, content);
	if (content == NULL)
		return (NULL);
	line = ft_extract_line(content);
	if (line == NULL && content)
	{
		free(content);
		content = NULL;
	}
	content = ft_update_contents_for_next_call(content);
	return (line);
}
