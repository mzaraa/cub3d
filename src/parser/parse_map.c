/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:18:23 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/18 18:56:33 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// should only have 1 (wall) or 0 (empty) and player position (N,S,E,W)
/* void	check_is_good_map(t_data *data)
{
	t_list	*tmp;

	tmp = data->map_list;
	while (tmp)
	{
		if (ft_strchr(tmp->content, ))
		{
			perror("Error\n Sprite not allowed in map");
			ft_exit_program(data);
		}
		tmp = tmp->next;
	}
} */

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
		else if (line[0] == '\n' || dodge_empty_line(line))
		{
			free(line);
			continue ;
		}
		//printf("line: %s", line);
		ft_lstadd_back(&data->map_list, ft_lstnew(ft_strdup(line)));
		free(line);
		i++;
	}
	if (i == 0)
	{
		perror("Error\nMissing map");
		ft_exit_program(data);
	}
}
