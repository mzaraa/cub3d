/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:22:35 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/16 18:00:12 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_identifier(t_data *data, int fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = gnl(fd);
		if (line == NULL)
			break ;
		if (check_line(data, line) == 0)
			break ;
	}
}
