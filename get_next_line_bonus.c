/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:29:22 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/04/09 20:40:03 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifdef BUFFER_SIZE
#endif

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*next_line;
	char		*result;
	int			j;

	j = 0;
	if (fd < 0 || fd > 1024)
		return (NULL);
	result = malloc(BUFFER_SIZE + 1);
	if (result == NULL)
		return (NULL);
	if (buffer[fd] == NULL)
		buffer[fd] = malloc(BUFFER_SIZE + 1);
	if (buffer[fd] == NULL)
		return (NULL);
	next_line = get_result(fd, j, buffer[fd], result);
	if (next_line == NULL)
	{
		free(buffer[fd]);
		free(result);
		buffer[fd] = NULL;
		result = NULL;
	}
	return (next_line);
}
