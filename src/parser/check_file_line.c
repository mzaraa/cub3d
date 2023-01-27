/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:24:53 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/27 14:01:18 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_line(t_data *data, char *trimed)
{
	const char		*tab[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	unsigned int	i;
	char			**split;

	i = 0;
	split = ft_split(trimed, WHITESPACE);
	while (tab[i])
	{
		// printf("(%s == %s) = %d\n", split[0], tab[i], )
		if (ft_strcmp(split[0], tab[i]) == 0)
		{
			check_double(data, i, trimed);
			data->id_tab[i].id = ft_strdup(tab[i]);
			if (i == F || i == C)
				data->id_tab[i].info_rgb = parse_rgb(data, trimed);
			else
				data->id_tab[i].info_tex = parse_tex(data, trimed);
			ft_free_split(split);
			return ;
		}
		i++;
	}
	ft_free_split(split);
	if (trimed)
		free(trimed);
	ft_exit_program(data, "Error\nInvalid identifier");
}
