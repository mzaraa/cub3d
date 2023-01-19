/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:23:31 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/14 13:32:46 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl(int fd)
{
	static int	BUFFER_SIZE = 5;
    char		*line;
    int			i;
    char		c;

	i = 0;
	line = (char *)malloc(BUFFER_SIZE);
    while (read(fd, &c, 1) > 0)
	{
        if(i == BUFFER_SIZE-1)
		{
            BUFFER_SIZE = BUFFER_SIZE * 2;
            line = ft_realloc(line, BUFFER_SIZE / 2, BUFFER_SIZE);
        }
        line[i] = c;
        i++;
        if (c == '\n')
		{
            line[i] = '\0';
            return (line);
        }
    }
    if(i > 0)
    {
        line[i] = '\0';
        return (line);
    }
    free(line);
    return NULL;
}
