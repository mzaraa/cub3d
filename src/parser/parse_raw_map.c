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

// void	check_each_line_map(t_data *data, char *s)
// {
// 	if (data->longest_line < ft_strlen(s))
// 		data->longest_line = ft_strlen(s);
// 	while (*s)
// 	{
// 		if (*s != '0' && *s != '1' && *s != 'N' && *s != 'S' && *s != 'E' && *s != 'W')
// 		{
// 			printf("Error\nInvalid map\n");
// 			ft_exit_program(data);
// 		}
// 		s++;
// 	}
// }

// // should only have 1 (wall) or 0 (empty) and player position (N,S,E,W)
// void	check_map(t_data *data)
// {
// 	t_list	*tmp;

// 	tmp = data->map_list;
// 	while (tmp)
// 	{
// 		ft_replace_char(tmp->content, ' ', '0');
// 		check_each_line_map(data, tmp->content);
// 		tmp = tmp->next;
// 	}
// 	tmp = data->map_list;
// 	while (tmp)
// 	{
// 		tmp->content = ft_realloc(tmp->content, ft_strlen(tmp->content), data->longest_line);
// 		tmp = tmp->next;
// 	}
// }

void	parse_raw_map(t_data *data, int fd)
{
	int		i;

	i = 0;
	while (1)
	{
		data->line_gnl = gnl(fd);
		if (data->line_gnl == NULL)
			break ;
		else if (data->line_gnl[0] == '\n' || dodge_empty_line(data->line_gnl))
		{
			free(data->line_gnl);
			continue ;
		}
		ft_lstadd_back(&data->map_list, ft_lstnew(ft_strtrim(data->line_gnl, "\n")));
		free(data->line_gnl);
		i++;
	}
	if (i == 0)
	{
		perror("Error\nMissing map");
		ft_exit_program(data);
	}
}
