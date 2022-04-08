/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:29:22 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/04/08 17:12:41 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#if BUFFER_SIZE
#endif
#include <stdio.h>

char	*get_result(int fd, char *buffer)
{
	static int	i;
	int			j;
	static int	control;
	char		*result;

	result = ft_calloc(1000000, sizeof(char));
	if (result == NULL)
		return (NULL);
	j = 0;
	if (control == i)
		control = read(fd, buffer, BUFFER_SIZE);
	if (control == 0)
		return (NULL);
	while (buffer[i] != '\n' && i < control)
	{
		result[j++] = buffer[i++];
		if (control == i)
		{
			//result = ft_realloc(result, ft_strlen(result) + BUFFER_SIZE);
			control = read(fd, buffer, BUFFER_SIZE);
			i = 0;
		}
	}
	if (buffer[i++] == '\n')
	{
		result[j++] = '\n';
		result[j] = '\0';
		return (result);
	}
	result[j] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0)
		return (NULL);
	if (buffer == NULL)
		buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	return (get_result(fd, buffer));
}

// #include <string.h>
// #include <stdio.h>

// int main()
// {
// 	FILE *ptr = fopen("test3.txt", "r");
// 	int fd = fileno(ptr);
// 	// int i = 0;
// 	// char *buffer = malloc(sizeof(char) * 70);
// 	// while (i < 6)
// 	// {
// 	// 	printf("%s", get_next_line(fd));
// 	// 	i++;
// 	// }
// 	// printf("%d\n", strcmp(get_next_line(fd), "01234567890123456789012345678901234567890\n"));
// 	// printf("%d\n", strcmp(get_next_line(fd),"987654321098765432109876543210987654321098\n"));
// 	// printf("%d\n", strcmp(get_next_line(fd),"0123456789012345678901234567890123456789012\n"));
// 	// printf("%d\n", strcmp(get_next_line(fd),"987654321098765432109876543210987654321098\n"));
// 	// printf("%d\n", strcmp(get_next_line(fd),"01234567890123456789012345678901234567890\n"));
// 	// printf("%d\n", strcmp(get_next_line(fd), 0));
// 	// char *result = get_next_line(0);
// 	// printf("%s\n", result);
// 	// printf("%s", get_next_line_two(fd));
// 	// printf("%zd\n", read(fd, buffer, 2));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	get_next_line(fd);
// 	return (0);
// }
