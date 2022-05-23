/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:56:33 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/04/09 20:29:34 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_result(int fd, int j, char *buffer, char *result)
{
	static int	i[1024];
	static int	control[1024];

	if (control[fd] <= i[fd])
	{
		control[fd] = read(fd, buffer, BUFFER_SIZE);
		i[fd] = 0;
	}
	if (control[fd] <= 0)
		return (NULL);
	while (buffer[i[fd]] != '\n' && i[fd] < control[fd] && control[fd] != 0)
	{
		result[j++] = buffer[i[fd]++];
		if (control[fd] == i[fd])
		{
			result = ft_realloc(result, ft_strlen(result) + BUFFER_SIZE);
			control[fd] = read(fd, buffer, BUFFER_SIZE);
			i[fd] = 0;
		}
	}
	if (buffer[i[fd]++] == '\n' && control[fd] != 0)
		result[j++] = '\n';
	result[j] = '\0';
	return (result);
}
