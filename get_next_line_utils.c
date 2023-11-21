/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:42:53 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/21 17:13:26 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_getlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*(str + len) != '\n' && *(str + len) != '\0')
		len++;
	return (len + (*(str + len) == '\n'));
}

static char	*ft_strncpy(char *dest, char *src, int n)
{
	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	return (dest);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*str;
	int		l_line;
	int		l_buffer;

	l_line = ft_getlen(line);
	l_buffer = ft_getlen(buffer);
	str = (char *)malloc(sizeof(char) * (l_line + l_buffer + 1));
	if (!str)
		return (NULL);
	*ft_strncpy(ft_strncpy(str, line, l_line), buffer, l_buffer) = '\0';
	if (line)
		free(line);
	return (str);
}

char	*ft_read(int fd, char *buffer)
{
	int	rd;

	while (buffer && *(buffer + rd) != '\n')
		
	else
		rd = read(fd, buffer, BUFFER_SIZE);
	if (rd < BUFFER_SIZE)
	{
		while (rd < BUFFER_SIZE)
			*(buffer + rd++) = '\0';
	}
	if (rd == 0)
	{
		free(buffer);
		buffer = NULL;
	}
	return (buffer);
}

char	*get_line(char *line, char *buffer, int fd)
{
	while (ft_read(fd, buffer))
	{
		line = ft_strjoin(line, buffer);
		if (*(line + ft_getlen(line) - 1) == '\n' || line == NULL)
			return (line);
	}
	return (line);
}
