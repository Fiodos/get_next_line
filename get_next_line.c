/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:29:22 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/04/04 19:03:35 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1) Try to figure out why the tester K.O you seemingly random
2) You need to find a way around the hardcoded char buffer, in order to be able to store
greater input
3) Try to find a way to work with increased buffer sizes
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#if BUFFER_SIZE
#endif
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_file_size(fd)
{
	int size;
	int c;

	size = 0;
	c = 0;
	while (read(fd, &c, 1))
		size++;
	return (size);
}

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];
	char	*result;
	char	c;
	int		i;
	int		control;

	i = 0;
	c = 0;
	control = read(fd, &c, 1);
	if (control <= 0)
		return (0);
	while (control && c != '\n')
	{
		buff[i] = c;
		i++;
		control = read(fd, &c, 1);
	}
	buff[i] = '\0';
	result = malloc(sizeof(char) * (ft_strlen(buff) + 1));
	i = 0;
	while (buff[i])
	{
		result[i] = buff[i];
		i++;
	}
	if (control <= 0)
	{
		result[i] = '\0';
		return (result);
	}
	result[i] = '\n';
	return (result);
}

#include <string.h>
int main()
{
	FILE *ptr = fopen("test5.txt", "r");
	int fd = fileno(ptr);
	// char *buff;
	// buff = malloc(sizeof(char) * 10000);
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// read(fd, buff, 100000);
	// printf("%s\n", buff);
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	printf("%d\n", get_file_size(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
