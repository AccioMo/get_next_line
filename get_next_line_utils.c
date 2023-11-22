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

char	*ft_strncpy(char *dest, char *src, int n)
{
	while (n > 0 && *src)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*str;
	int		l_line;
	int		l_buffer;

	if (line == NULL && buffer == NULL)
		return (NULL);
	l_line = ft_getlen(line);
	l_buffer = ft_getlen(buffer);
	str = (char *)malloc(sizeof(char) * (l_line + l_buffer + 1));
	if (!str)
		return (NULL);
	ft_strncpy(ft_strncpy(str, line, l_line), buffer, l_buffer);
	if (line)
		free(line);
	return (str);
}

char	*ft_read(int fd, char *buffer)
{
	int	rd;

	rd = 0;
	
	while (*(buffer + rd) && *(buffer + rd) != '\n')
		rd++;
	if (*(buffer + rd) == '\n')
	{
		rd++;
		ft_strncpy(buffer, buffer + rd, BUFFER_SIZE - rd);
		rd = BUFFER_SIZE;
	}
	else
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
		{
			free(buffer);
			return (NULL);
		}
	}
	*(buffer + rd) = '\0';
	return (buffer);
}
