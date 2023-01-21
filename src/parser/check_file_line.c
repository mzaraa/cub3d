/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:24:53 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/21 12:14:18 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_line(t_data *data, char *trimed)
{
	const t_tuple	tab[] = {{"NO", NO, 2}, {"SO", SO, 2}, {"WE", WE, 2},
	{"EA", EA, 2}, {"F", F, 1}, {"C", C, 1}, {NULL, TOTAL, 0}};
	unsigned int	i;

	i = 0;
	while (tab[i].id_str)
	{
		if (ft_strncmp(trimed, tab[i].id_str, tab[i].i) == 0)
		{
			check_double(data, tab[i].enum_v, trimed);
			data->id_tab[tab[i].enum_v].id = ft_strdup(tab[i].id_str);
			if (tab[i].enum_v == F || tab[i].enum_v == C)
				data->id_tab[tab[i].enum_v].info_rgb = parse_rgb(data, trimed);
			else
				data->id_tab[tab[i].enum_v].info_tex = parse_tex(data, trimed);
			return ;
		}
		i++;
	}
	if (trimed)
		free(trimed);
	if (data->line_gnl)
		free(data->line_gnl);
	ft_exit_program(data, "Error\nInvalid identifier");
}
