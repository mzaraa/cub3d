/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:31:04 by mzaraa            #+#    #+#             */
/*   Updated: 2023/02/19 17:13:46 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_player_inside_map(t_data *data)
{
	if (data->player_dir == 0)
	{
		free(data->map);
		data->map = NULL;
		ft_exit_program(data, "Error\nNeed to have player inside the map");
	}
	if (((data->ppy - 1 >= 0 \
	&& data->ppy + 1 < ft_lstsize(data->map_list)) \
	&& (data->ppx - 1 >= 0 \
	&& data->ppx + 1 < (int)ft_strlen(data->map[data->ppy]))) \
	&& ft_strchr("01", data->map[data->ppy - 1][data->ppx]) \
	&& ft_strchr("01", data->map[data->ppy + 1][data->ppx]) \
	&& ft_strchr("01", data->map[data->ppy][data->ppx - 1]) \
	&& ft_strchr("01", data->map[data->ppy][data->ppx + 1]))
	{
		return ;
	}
	free(data->map);
	data->map = NULL;
	ft_exit_program(data, "Error\nNeed to have player inside the map");
}

// check for each '0' if it's near outside of the map, if it is, it's not closed
void	check_map_closed(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '0')
			{
				if (cell_surrounded(data, i, j))
				{
					ft_exit_program(data, "Error\nMap not closed");
				}
			}
		}
	}
}

void	check_pos_player(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (ft_strchr("NSEW", data->map[i][j]))
			{
				data->ppx = j;
				data->ppy = i;
				data->player_dir = data->map[i][j];
				data->map[i][j] = '0';
				count++;
			}
			if (count > 1)
				ft_exit_program(data, "Error\nNeed only 1 player position");
		}
	}
}

void	fill_map(t_data *data)
{
	t_list	*tmp;
	int		i;

	tmp = data->map_list;
	data->map = malloc(sizeof(char *) * (ft_lstsize(data->map_list) + 1));
	i = 0;
	while (tmp)
	{
		data->map[i] = ((char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	data->map[i] = NULL;
	check_pos_player(data);
	check_map_closed(data);
	check_player_inside_map(data);
}
