/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:46:03 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/20 22:02:18 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("file", 0);
	/*		line: 1		*/
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	/*		line: 2		*/
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	/*		line: 3		*/
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	/*		line: 4		*/
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	/*		line: 5		*/
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	/*		line: 6		*/
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	/*		line: 7		*/
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	/*		line: 8		*/
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	// system("leaks a.out");
	return (0);
}
