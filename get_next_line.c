/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:29:22 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/04/07 17:07:48 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#if BUFFER_SIZE
#endif

// char	*get_next_line(int fd)
// {
// 	void	*buff;
// 	// int		c;
// 	int		i;
// 	int		control;
// 	int		buff_size;

// 	// c = 0;
// 	i = 0;
// 	buff_size = BUFFER_SIZE;
// 	buff = malloc(sizeof(char) * buff_size);
// 	if (buff == 0)
// 		return (0);
// 	control = read(fd, (char *)buff, 1);
// 	if (control <= 0)
// 		return (0);
// 	while (((char)buff + i) != '\n' && control != 0)
// 	{
// 		i++;
// 		if (i == buff_size)
// 			buff = ft_realloc(buff, buff_size *= 5);
// 		control = read(fd, ((char *)buff + i), 1);
// 	}
// 	if (control <= 0)
// 		*((char *)buff + i) = '\0';
// 	else
// 		*((char *)buff + (i++))  = '\n';
// 	*((char *)buff + i)  = '\0';
// 	return (buff);
// }

#include <stdio.h>



char	*get_next_line_two(int fd)
{
	static char	*buffer;
	char		*result;
	static int	i;
	static int	control;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1); // needs to be called once. if control == BUFFER_SIZE after a read call occured, need to realloc more (*2 or *i maybe);
	if (buffer == NULL)
		return (NULL);
	result = malloc(sizeof(char) * BUFFER_SIZE + 1); // needs to be called everytime a new line begin. needs to be realloced when line (i) > BUFFER_SIZE;
	if (result == NULL)
		return (NULL);
	control = read(fd, buffer, BUFFER_SIZE); // needs to be called again when control == BUFFER_SIZE;
	while (buffer[i] != '\n' && i < control)
	{
		result[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		result[i] = '\n';
		result[i + 1] = '\0';
	}
	return (result);
}

#include <string.h>
#include <stdio.h>

int main()
{
	FILE *ptr = fopen("test4.txt", "r");
	int fd = fileno(ptr);
	// int i = 0;
	// char *buffer = malloc(sizeof(char) * 70);
	// while (i < 6)
	// {
	// 	printf("%s", get_next_line(fd));
	// 	i++;
	// }
	// printf("%d\n", strcmp(get_next_line(fd), "01234567890123456789012345678901234567890\n"));
	// printf("%d\n", strcmp(get_next_line(fd),"987654321098765432109876543210987654321098\n"));
	// printf("%d\n", strcmp(get_next_line(fd),"0123456789012345678901234567890123456789012\n"));
	// printf("%d\n", strcmp(get_next_line(fd),"987654321098765432109876543210987654321098\n"));
	// printf("%d\n", strcmp(get_next_line(fd),"01234567890123456789012345678901234567890\n"));
	// printf("%d\n", strcmp(get_next_line(fd), 0));
	// char *result = get_next_line(0);
	// printf("%s\n", result);
	printf("%s", get_next_line_two(fd));
	return (0);
}
