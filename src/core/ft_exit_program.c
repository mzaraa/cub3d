/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:51:47 by mzaraa            #+#    #+#             */
/*   Updated: 2023/03/01 13:39:03 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_sec(t_data *data)
{
	if (data->line_gnl)
		free(data->line_gnl);
	if (data->map)
		free(data->map);
	if (data->map_list)
		ft_lstclear(&data->map_list, free);
	if (data->tex)
		ft_free_split_i(data->tex, data);
	free(data);
	exit(1);
}

int	ft_exit_program(t_data *data, char *s)
{
	static int	i = -1;

	printf("%s\n", s);
	if (data->id_tab != NULL)
	{
		while (++i < TOTAL)
		{
			if (data->id_tab[i].id)
				free(data->id_tab[i].id);
			if (data->id_tab[i].info_tex)
				free(data->id_tab[i].info_tex);
			else if (data->id_tab[i].info_rgb)
				free(data->id_tab[i].info_rgb);
		}
		free(data->id_tab);
		data->id_tab = NULL;
	}
	ft_exit_sec(data);
	exit(1);
}
