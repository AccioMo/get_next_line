/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:44:10 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/10/04 16:45:35 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_gnl_strjoin(char *line, char *buffer);
char	*ft_read(int fd, char *buffer);
int		ft_gnl_strlen(char *str);
int		ft_bufferlen(char *str);

#endif
