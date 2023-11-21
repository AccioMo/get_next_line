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

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*leftovers = NULL;

	if (fd < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	if (leftovers)
		line = leftovers;
	else
		line = NULL;
	line = get_line(line, buffer, fd);
	if (buffer)
		leftovers = ft_strjoin(NULL, buffer + ft_getlen(buffer));
	return (line);
}
