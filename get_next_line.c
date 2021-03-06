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
	static char	*buffer;
	char		*next_line;
	char		*result;
	int			j;

	j = 0;
	result = malloc(BUFFER_SIZE + 1);
	if (result == NULL)
		return (NULL);
	if (buffer == NULL)
		buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	next_line = get_result(fd, j, buffer, result);
	if (next_line == NULL)
	{
		free(buffer);
		free(result);
		buffer = NULL;
		result = NULL;
	}
	return (next_line);
}
