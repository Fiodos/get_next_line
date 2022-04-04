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


// The function really only need to return one line at a time
// If nothing to read or error occured, return NULL;
// Should be able to read from file + standard input
// The returned line should incluude the terminating null char
// except the end of line is reached, and it does not end with \n

// Try it out with read to a char. Then if char != '\n', say buffer (which will be an array with buffer size)
// buff[i] = c. If c == '\n' break. Then get len of buffer. Allocate the memory to a ptr. Copy buff
// content into ptr and return it.


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char	buff[100];
	char	*result;
	int		c;
	int		i;

	i = 0;
	c = 0;
	read(fd, &c, 1);
	if (c == 0)
		return (0);
	while (i < 100)
	{
		if (c == '\n')
			break;
		if (c == (-1))
			break;
		buff[i] = c;
		read(fd, &c, 1);
		i++;
	}
	buff[i] = '\0';
	result = malloc(sizeof(char) * ft_strlen(buff));
	i = 0;
	while (buff[i])
	{
		result[i] = buff[i];
		i++;
	}
	if (c == (-1))
		result[i] = '\0';
	else
		result[i] = '\n';
	return (result);
}

// #include <string.h>
// int main()
// {
// 	FILE *ptr = fopen("test2.txt", "r");
// 	int fd = fileno(ptr);
// 	char buff[100];
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	return (0);
// }
