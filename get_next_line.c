/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:42:24 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/21 13:30:36 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || fd > INT_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (read(fd, 0, 0) == -1)
	{
		if (buffer)
			free(buffer);
			buffer = NULL;
		return (NULL);
	}
	line = NULL;
	if (!buffer)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		buffer[BUFFER_SIZE] = '\0';
		*buffer = '\0';
	}
	while (buffer)
	{
		buffer = ft_read(fd, buffer);
		line = ft_strjoin(line, buffer);
		if (*(line + ft_strlen(line) - 1) == '\n')
			return (line);
		if (line == NULL)
		{
			if (buffer)
			{
				free(buffer);
				buffer = NULL;
			}
			return (NULL);
		}
	}
	return (line);
}
