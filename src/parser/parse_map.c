/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:18:23 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/17 18:33:33 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO : fix segfault HERE
void	parse_map(t_data *data, int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (1)
	{
		line = gnl(fd);
		if (line == NULL)
			break ;
		else if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		ft_lstadd_back(&data->map_list, ft_lstnew(ft_strdup(line)));
		free(line);
		i++;
	}
	if (i == 0)
	{
		perror("Error: Missing map");
		ft_exit_program(data);
	}
}
