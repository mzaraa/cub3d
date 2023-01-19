/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:51:47 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/18 18:15:09 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// todo : free all the data
void	ft_exit_program(t_data *data)
{
	int i;

	i = 0;
	if (data->id_tab != NULL) {
		while (i < TOTAL)
		{
			if (data->id_tab[i].id != NULL)
				free(data->id_tab[i].id);
			if (data->id_tab[i].info_tex != NULL)
				free(data->id_tab[i].info_tex);
			else if (data->id_tab[i].info_rgb != NULL)
				free(data->id_tab[i].info_rgb);
			i++;
		}
		free(data->id_tab);
		data->id_tab = NULL;
	}
	if (data->map_list)
		ft_lstclear(&data->map_list, free);
	ft_free_split(data->map);
	free(data);
	// printf("Exiting program");
	exit(1);
}
