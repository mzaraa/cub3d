/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:06:48 by mzaraa            #+#    #+#             */
/*   Updated: 2023/02/19 17:13:02 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cell_surrounded(t_data *data, int i, int j)
{
	if ((!((i - 1) >= 0) || !ft_strchr("01NEWS", data->map[i - 1][j])) \
			|| (!((i + 1) < (int)ft_lstsize(data->map_list)) \
			|| !ft_strchr("01NEWS", data->map[i + 1][j])) \
			|| (!((j - 1) >= 0) || !ft_strchr("01NEWS", data->map[i][j - 1])) \
			|| (!((j + 1) <= (int)data->longest_line) \
			|| !ft_strchr("01NEWS", data->map[i][j + 1])))
	{
		return (1);
	}
	return (0);
}

int	ft_split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_replace_char(char *str, char find, char replace)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == find)
			str[i] = replace;
		i++;
	}
}
