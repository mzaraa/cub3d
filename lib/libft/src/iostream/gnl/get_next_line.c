/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:23:31 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/20 12:34:35 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl(int fd)
{
	static int	buffer_size = 100;
	char		*line;
	int			i;
	char		c;

	i = 0;
	line = (char *)malloc(buffer_size);
	ft_bzero(line, buffer_size);
	while (read(fd, &c, 1) > 0)
	{
		if (i == buffer_size - 1)
		{
			buffer_size = buffer_size * 2;
			line = ft_realloc(line, buffer_size / 2, buffer_size);
		}
		line[i++] = c;
		if (c == '\n')
			return (line);
	}
	if (i > 0)
		return (line);
	free(line);
	return (NULL);
}
