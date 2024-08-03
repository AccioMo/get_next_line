/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:14:04 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/24 13:16:35 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	allocate_buffer(char **buffer)
{
	if (!*buffer)
	{
		*buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!*buffer)
			return (0);
		*(*buffer + BUFFER_SIZE) = '\0';
		**buffer = '\0';
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > INT_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	line = NULL;
	if (!allocate_buffer(&buffer[fd]))
		return (NULL);
	while (buffer[fd])
	{
		buffer[fd] = ft_read(fd, buffer[fd]);
		line = ft_strjoin(line, buffer[fd]);
		if (line == NULL)
			return (free(buffer[fd]), buffer[fd] = NULL, line);
		if (*(line + ft_strlen(line) - 1) == '\n')
			return (line);
	}
	return (line);
}
