/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:29:22 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/04/06 17:12:07 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#if BUFFER_SIZE
#endif

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int	get_file_size(fd)
// {
// 	int size;
// 	int c;
// 	static int buff_size = BUFFER_SIZE;

// 	size = 0;
// 	c = 0;
// 	if (!buff_size)
// 		return (0);
// 	while (read(fd, &c, 1))
// 		size++;
// 	return (size);
// }

// char	*get_next_line(int fd)
// {
// 	char	*buff;
// 	// char	*result;
// 	char	c;
// 	int		i;
// 	int		control;

// 	i = 0;
// 	c = 0;
// 	control = read(fd, &c, 1);
// 	if (control <= 0)
// 		return (0);
// 	buff = malloc(sizeof(char) * 1);
// 	if (buff == 0)
// 		return (0);
// 	while (control && c != '\n')
// 	{
// 		buff[i] = c;
// 		i++;
// 		control = read(fd, &c, 1);
// 	}
// 	// buff[i] = '\0';
// 	// result = malloc(sizeof(char) * (ft_strlen(buff) + 1));
// 	// i = 0;
// 	// while (buff[i])
// 	// {
// 	// 	result[i] = buff[i];
// 	// 	i++;
// 	// }
// 	if (control <= 0)
// 	{
// 		buff[i] = '\0';
// 		return (buff);
// 	}
// 	buff[i] = '\n';
// 	return (buff);
// }

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	i = 0;
	if (dst == 0 && src == 0)
		return (dst);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

char	*ft_realloc(char *ptr, int len)
{
	char	*result;

	result = malloc(sizeof(char) * len);
	if (result == 0)
		return (0);
	ft_memcpy(result, ptr, ft_strlen(ptr));
	free(ptr);
	ptr = 0;
	return (result);
}

char	*get_next_line(int fd)
{
	char	*buff;
	int		c;
	int		i;
	int		control;
	int		buff_size;

	c = 0;
	i = 0;
	buff_size = BUFFER_SIZE;
	control = read(fd, &c, 1);
	if (control <= 0)
		return (0);
	buff = malloc(sizeof(char) * buff_size);
	while (c != '\n' && control != 0)
	{
		buff[i] = c;
		i++;
		if (i == buff_size)
			buff = ft_realloc(buff, buff_size *= 5);
		control = read(fd, &c, 1);
	}
	if (control <= 0)
	{
		buff[i] = '\0';
		return (buff);
	}
	buff[i] = '\n';
	return (buff);
}

// #include <string.h>
// int main()
// {
// 	// FILE *ptr = fopen("multiple_line_no_nl", "r");
// 	// int fd = fileno(ptr);
// 	// int i = 0;

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
// 	char *result = get_next_line(0);
// 	printf("%s\n", result);
// 	return (0);
// }
